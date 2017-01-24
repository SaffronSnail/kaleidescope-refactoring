#pragma once

#include "expression.hpp"

#include <memory>

namespace Kaleidoscope
{
namespace Parse
{

class BinaryExpression : public Expression
{
public:
  BinaryExpression(char op, std::unique_pointer<Expression> lhs,
                                  std::unique_pointer<Expression rhs)
    : op(op), lhs(lhs), rhs(rhs)
  {}

private:
  char op;
  std::unique_pointer<Expression> lhs, rhs;
};

} // namespace Parse
} // namespace Kaleidoscope

