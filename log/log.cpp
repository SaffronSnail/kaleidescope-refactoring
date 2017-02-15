#include "log.hpp"

#include <iostream>

namespace Kaleidoscope
{
namespace Log
{
void log_error(std::string message)
{
  std::cerr << message << std::endl;
}
} // namespace Log
} // namespace Kaleidoscope

