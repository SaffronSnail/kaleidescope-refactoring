#pragma once

#include "expression.hpp"

#include <string>

#include "project-config.hpp"

namespace KaleidescopeLang
{
namespace AST
{
  class Variable : public Expression
  {
  public:
    Variable(String name);

    String GetName();

  private:
    String name;
  };
}
}
