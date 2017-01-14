#include "binary-operator.hpp"

KaleidescopeLang::AST::BinaryOperator::BinaryOperator(char op, Operand lhs, Operand rhs)
  : op(op), lhs(std::move(lhs)), rhs(std::move(rhs))
{
}
