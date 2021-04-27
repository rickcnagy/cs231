#include <string>
#include <unistd.h>
#include <sys/socket.h>

const int PORT = 8080;

int open_tcp_socket();
void bind_to_socket(int socket_fd);
void listen_on_socket(int socket_fd);
int accept_connection(int socket_fd);
const char *read_request(int connection_socket_fd);
const char *build_response(const char *request_message);

int main() {
  const int socket_fd = open_tcp_socket();

  bind_to_socket(socket_fd);
  listen_on_socket(socket_fd);

  while (true) {
    const int connection_socket_fd = accept_connection(socket_fd);

    const char *request_message = read_request(connection_socket_fd);
    const char *response_message = build_response(request_message);

    write(connection_socket_fd, response_message,
          std::strlen(response_message));
    close(connection_socket_fd);
  }

  return 0;
}

int open_tcp_socket() {
  const int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("Error opening socket");
    exit(EXIT_FAILURE);
  }
  return socket_fd;
}

void bind_to_socket(int socket_fd) {}

void listen_on_socket(int socket_fd) {}

int accept_connection(int socket_fd) { return 0; }

const char *read_request(int connection_socket_fd) { return (char *)""; }

const char *build_response(const char *request_message) { return (char *)""; }
