#pragma once

#include "string.hpp"

namespace Kaleidoscope
{
namespace Lexer
{

struct Token
{
  /**
   * @brief This tag indicates what kind of token we hav (avoids RTTI). The
   * value may be one of the items in this enum, or it may be a character when,
   * for example, an identifier is being parsed (this is why it explicitly
   * derives from signed int, so that an optimizatnoi doesn't make the assignment
   * of a character to this variable error-prone);
   */
  enum class Type : signed int
  {
    eof = -1,

    def = -2,
    ext = -3,

    identifier = -4,
    number = -5,
    comment = -6,
  } type;

  Token(Type t) : type(t)
  {}

  virtual bool equal(const Token *other) const;
};

bool equivalent_tokens(const Token *lhs, const Token *rhs);
String to_string(Token::Type t);

} // namespace Lexer
} // namespace Kaleidoscope

