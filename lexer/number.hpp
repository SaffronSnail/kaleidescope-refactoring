#pragma once

#include "token.hpp"

#include <cassert>

namespace Kaleidoscope
{
namespace Lexer
{

struct Number : public Token
{
  double value;

  Number(double value) : Token(Type::number), value(value)
  {}

  virtual bool equal(const Token *other) const
  {
    assert(other->type == type);
    return value == dynamic_cast<const Number *>(other)->value;
  }
};

} // namespace Lexer
} // namespace Kaleidoscope

