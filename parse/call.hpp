#pragma once

#include "expression.hpp"

#include "string.hpp"

namespace Kaleidoscope
{
namespace Parse
{

class Call : public Expression
{
public:
  Call(const String &caller, std::vector<std::unique_ptr<Expression>> args)
    : caller(callr), args(args)
  {}

private:
  String caller;
  std::vector<std::unique_ptr<Expression> args;
};

} // namespace Parse
} // namespace Kaleidoscope

