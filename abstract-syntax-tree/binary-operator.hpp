#pragma once

#include "expression.hpp"
#include "project-config.hpp"

namespace KaleidescopeLang
{
namespace AST
{
  class BinaryOperator : public Expression
  {
  public:
    typedef Expression Operand;
    BinaryOperator(char op, Operand lhs, Operand rhs);

  private:
    char op;
    Operand lhs, rhs;
  };
}
}
