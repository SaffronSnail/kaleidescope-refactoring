#include "log.hpp"

#include <iostream>

void log_error(std::string message)
{
  std::cerr << message << std::endl;
}
