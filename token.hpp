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
    eof = -1,

    // commands
    def = -2,
    k_extern = -3,

    // primary
    identifier = -4,
    number = -5,
    comment = -6,
  } tag;

  Token(Tag tag) : tag(tag) {}
  virtual ~Token() {}
};

struct Comment : public Token
{
  String content;

  Comment(String content) : Token(comment), content(content) {}
};

struct Identifier : public Token
{
  String name;

  Identifier(String name) : Token(identifier), name(name) {}
};

struct Numeral : public Token
{
  double value;

  Numeral(double value) : Token(number), value(value) {}
};

} // namespace KaleidescopeLang

