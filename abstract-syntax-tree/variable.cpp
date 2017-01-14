#include "variable.hpp"

KaleidescopeLang::AST::Variable::Variable(String name) : name(name)
{
}

KaleidescopeLang::String KaleidescopeLang::AST::Variable::GetName()
{
  return name;
}

