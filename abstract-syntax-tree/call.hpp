#pragma once

#include "expression.hpp"
#include "function.hpp"
#include "project-config.hpp"

#include <vector>

namespace KaleidescopeLang
{
namespace AST
{
  class Call : public Expression
  {
  public:
    Call(Function callee, std::vector<Expression> args);

  private:
    Function callee;
    std::vector<Expression> args;
  };
}
}
