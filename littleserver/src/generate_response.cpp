// Logic for generating an HTTP response given a request string - so essentially
// the "application" part of this server.

#include "generate_response.h"

#include <iostream>
#include <regex>
#include <string>

const std::string ERROR_500 = "HTTP/1.1 500 Internal Server Error";
const std::string ERROR_404 = "HTTP/1.1 404 Not Found";
const std::string ERROR_400 = "HTTP/1.1 400 Bad Request";

Request build_request(std::string raw_request);
std::string generate_plain_text_200(std::string body);
std::string get_query_param_value(Request request, std::string param_name);

// Generates a valid HTTP response no matter the request. If it's a valid
// request, we'll respond with a 200 and appropriate hello world body (including
// support for query params!), and if it's somehow invalid (non-root path, not
// GET, etc), we respond with the proper HTTP error response.
std::string generate_hello_world_response(const std::string raw_request) {
  struct Request request;
  try {
    request = build_request(raw_request);
  } catch (std::regex_error e) {
    return ERROR_400;
  }

  if (request.protocol != "HTTP/1.1") {
    return ERROR_500;
  }

  if (request.method != "GET") {
    return ERROR_500;
  }

  if (request.path != "/") {
    return ERROR_404;
  }

  std::string name = get_query_param_value(request, "name");
  if (name.empty()) {
    return generate_plain_text_200(
        "Hello, world! Tip: add ?name=$YOUR_NAME to the URL to get a custom "
        "message :)");
  } else {
    return generate_plain_text_200("Hello, " + name + "!");
  }
}

// Builds a Request struct that captures raw_request, parsed according to the
// HTTP RFC.
Request build_request(std::string raw_request) {
  Request request = Request();

  // Matching against HTTP start-lines, e.g. GET /?a=b HTTP/1.1
  std::regex start_line_regex("([A-Z]+) ([^\? ]+)(\\?.+)* (.+)");
  std::smatch match;
  std::regex_search(raw_request, match, start_line_regex);

  request.method = match[1];
  request.path = match[2];
  request.query_params = match[3];
  request.protocol = match[4];

  return request;
}

// Generates a 200 response with the supplied body
std::string generate_plain_text_200(std::string body) {
  return "HTTP/1.1 200 OK\n"
         "Content-type: plaintext\n"
         "Content-length: " +
         std::to_string(body.length()) +
         "\n"
         "\n" +
         body +
         "\n";
}

// Gets the value for the query param named param_name. If there's no such
// param, an empty string is returned.
std::string get_query_param_value(Request request, std::string param_name) {
  std::regex value_regex(param_name + "=([^&]+)");
  std::smatch match;
  if (std::regex_search(request.query_params, match, value_regex)) {
    return match[1];
  } else {
    return "";
  }
}
