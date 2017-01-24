#pragma once

#include "expression.hpp"

#include "string.hpp"

namespace Kaleidoscope
{
namespace Parse
{

class Variable : public Expression
{
public:
  Variable(const String &name) : name(name)
  {}

private:
  String name;
};

} // namespace Parse
} // namespace Kaleidoscope

