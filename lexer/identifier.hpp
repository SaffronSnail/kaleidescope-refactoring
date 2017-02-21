#pragma once

#include "string.hpp"

#include <cassert>

namespace Kaleidoscope
{
namespace Lexer
{

struct Identifier : public Token
{
  String name;

  Identifier(String name) : Token(Type::identifier), name(name)
  {}

  virtual bool equal(const Token *other) const
  {
    assert(type == other->type);
    return name == dynamic_cast<const Identifier *>(other)->name;
  }
};

} // namespace Lexer
} // namespace Kaleidoscope

