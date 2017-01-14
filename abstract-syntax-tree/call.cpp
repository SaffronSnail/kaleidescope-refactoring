#include "call.hpp"

KaleidescopeLang::AST::Call::Call(String callee, std::vector<Expression> args)
  : callee(callee), args(args)
{
}
