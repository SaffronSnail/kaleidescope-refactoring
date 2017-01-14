#pragma once

#include "expression.hpp"
#include "project-config.hpp"

#include <vector>

namespace KaleidescopeLang
{
namespace AST
{
  class Prototype : public Base
  {
  public:
    Prototype(String name, std::vector<String> args);

  private:
    String name;
    std::vector<String> args;
  };

  class Function
  {
  public:
    Function(Prototype prototype, Expression body);

  private:
    Prototype prototype;
    Expression body;
  };
}
}