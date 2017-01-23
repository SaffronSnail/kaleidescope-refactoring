#pragma once

#include "string.hpp"

namespace Kaleidoscope
{
namespace Lexer
{

struct Identifier : public Token
{
  String name;

  Identifier(String name) : Token(Type::identifier), name(name)
  {}
};

} // namespace Lexer
} // namespace Kaleidoscope
