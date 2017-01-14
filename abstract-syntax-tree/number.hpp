#pragma once

#include "expression.hpp"

namespace KaleidescopeLang
{
namespace AST
{
  class Number : public Expression
  {
  public:
    Number(double value);
    virtual UniqueIdentifier get_unique_identifier();

  private:
    double value;
  };
}
}
