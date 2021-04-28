#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <time.h>
#include <unistd.h>

#include <iostream>

#include "generate_response.h"

const int MAX_PENDING_CONNECTIONS = 100;
const int MAX_REQUEST_BYTES = 1500;

int main() {
  // Create an unbound TCP/IP socket
  const int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

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
  bind(socket_fd, (sockaddr *)&address, sizeof(address));

  // Start listening on our bound socket
  listen(socket_fd, MAX_PENDING_CONNECTIONS);

  std::cout << "Listening on http://localhost:" << port << std::endl;

  // Poll the incoming request queue and respond to each request with the return
  // value of generate_response().
  while (true) {
    // Pick the next incoming connection off the connection queue
    const int connection_fd = accept(socket_fd, NULL, NULL);

    std::cout << "--------Incoming request--------" << std::endl;

    // Read the request
    char request[MAX_REQUEST_BYTES] = {0};
    const int received_bytes =
        recv(connection_fd, request, MAX_REQUEST_BYTES, 0);
    std::cout << request << std::endl;

    // Generate a response and send to the client
    std::string response = generate_response(request);
    std::cout << response << std::endl << std::endl;
    const int sent_bytes =
        send(connection_fd, response.c_str(), response.length(), 0);

    // Close the connection socket
    close(connection_fd);
  }
}
