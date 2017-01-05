#pragma once

#include "project-config.hpp"

namespace KaleidescopeLang
{

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
struct Token
{
  enum Tag : signed char
  {
    tok_eof = -1,

    // commands
    tok_def = -2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5,
  } tag;

  Token(Tag tag) : tag(tag) {}
};

struct Identifier : public Token
{
  String name;

  Identifier(String name) : Token(tok_identifier), name(name) {}
};

struct Numeral : public Token
{
  double value;

  Numeral(double value) : Token(tok_number), value(value) {}
};

} // namespace KaleidescopeLang

