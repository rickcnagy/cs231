#include <string>

#ifndef GENERATE_RESPONSE_H
#define GENERATE_RESPONSE_H

std::string generate_response(const std::string rawRequest);

struct Request {
  std::string method;
  std::string protocol;
  std::string path;
  std::string query_params;
};

#endif
