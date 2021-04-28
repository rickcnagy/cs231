// Headers for generate_response

#include <string>

#ifndef GENERATE_RESPONSE_H
#define GENERATE_RESPONSE_H

std::string generate_hello_world_response(const std::string raw_request);

struct Request {
  std::string method;
  std::string protocol;
  std::string path;
  std::string query_params;
};

#endif
