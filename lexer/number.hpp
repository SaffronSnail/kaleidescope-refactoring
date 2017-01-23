#pragma once

#include "token.hpp"

namespace Kaleidoscope
{
namespace Lexer
{

struct Number : public Token
{
  double value;

  Number(double value) : Token(Type::number), value(value)
  {}
};

} // namespace Lexer
} // namespace Kaleidoscope

