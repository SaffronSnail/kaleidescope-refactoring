#pragma once

#include "expression.hpp"

#include "string.hpp"

namespace Kaleidoscope
{
namespace Parse
{

class Prototype
{
public:
  Prototype(const String &name, std::vector<String> args)
    : name(name), args(args)
  {}

private:
  String name;
  std::vector<String> args;
};

} // namespace Parse
} // namespace Kaleidoscope

