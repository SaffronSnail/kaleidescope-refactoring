#pragma once

#include "expression.hpp"

namespace Kaleidoscope
{
namespace Parse
{

class Number : public Expression
{
public:
  Number(double value) : value(value)
  {}

private:
  double value;
};

} // namespace Parse
} // namespace Kaleidoscope

