#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <time.h>

const int MAX_PENDING_CONNECTIONS = 1;
const int MAX_REQUEST_BYTES = 1000;

std::string get_response(std::string request) {
  if (request.find("GET / ") == 0) {
    const std::string body = "ricktest";

    return "HTTP/1.1 200 OK\n"
           "Content-type: plaintext\n"
           "Content-length: " + std::to_string(body.length()) + "\n"
           "\n" +
           body;
  } else {
    return "HTTP/1.1 404 Not Found";
  }
}

int main() {
  // Create an unbound TCP/IP socket
  const int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Error opening socket");
    exit(EXIT_FAILURE);
  }

  // Grab a random, non-privileged port to bind to
  srand(time(NULL));
  const int port = rand() % 64512 + 1023;

  // Construct the address we'll bind to
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  // Try to bind our socket to our address
  if (bind(socket_fd, (sockaddr *)&address, sizeof(address)) == -1) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  // Start listening on our bound socket
  if (listen(socket_fd, MAX_PENDING_CONNECTIONS) == -1) {
    perror("Error listening to bound socket");
    exit(EXIT_FAILURE);
  }

  std::cout << "Listening at http://localhost:" << port
            << std::endl;

  // Indefinitely poll the incoming request queue and respond to each request
  // with the return value of get_response().
  while (true) {
    // Pick the next incoming connection off the connection queue
    const int connection_fd = accept(socket_fd, NULL, NULL);
    if (connection_fd == -1) {
      perror("Error accepting incoming connection");
      exit(EXIT_FAILURE);
    }
    std::cout << "--------Incoming request--------" << std::endl;

    // Read the request
    char request[MAX_REQUEST_BYTES] = {0};
    const int received_bytes =
        recv(connection_fd, request, MAX_REQUEST_BYTES, 0);
    if (received_bytes == -1) {
      perror("Error receiving incoming message");
      exit(EXIT_FAILURE);
    }
    std::cout << request << std::endl;

    // Generate a response and send to the client
    std::string response = get_response(request);
    std::cout << response << std::endl << std::endl;
    const int sent_bytes =
        send(connection_fd, response.c_str(), response.length(), 0);
    if (sent_bytes < response.length()) {
      perror("Error sending response");
      exit(EXIT_FAILURE);
    }

    // Close the request connection
    close(connection_fd);
  }
}
