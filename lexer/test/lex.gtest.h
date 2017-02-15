#pragma once

#include "../lex.hpp"
using Kaleidoscope::Lexer;

#include <string>

typedef std::string String;

class StringSource : public SourceIterator
{
public:
  StringSource(String str) : source(str), pos(source.begin())
  {}

  virtual char operator*()
  {
    return *pos;
  }

  virtual SourceIterator *next()
  {
    ++pos;
    return this;
  }

  virtual SourceIterator *previous()
  {
    --pos;
    return this;
  }

  virtual SourceIterator *copy() const
  {
    return new SourceIterator(source);
  }

private:
  String source;
  String::const_iterator pos;
};

// this is useful when you have a string that you want to parse one token
// out of; it creates the test, lexes once, and expects it to be the specified
// token
#define SIMPLE_TOKEN_TEST(test_name, string_to_parse, expected_token)\
  TEST(lexer, test_name)\
  {\
    StringIterator test_target(string_to_parse);\
    EXPECT_EQ(expected_token, *lex(test_target, test_target.end()));\
  }

static const Token end_tok = Token(Token::Type::eof);
SIMPLE_TOKEN_TEST(finds_end, "", end_tok);
SIMPLE_TOKEN_TEST(ignore_whitespace,
           "        \t\t\t\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n",
           end_tok
)
SIMPLE_TOKEN_TEST(ignore_comment, "# this is a comment", end_tok)

SIMPLE_TOKEN_TEST(parse_integer, "500", Number(500))
SIMPLE_TOKEN_TEST(parse_rational, "123.456", Number(123.456))

SIMPLE_TOKEN_TEST(pase_keyword_def, "def", Token(Token::Type::def))
SIMPLE_TOKEN_TEST(parse_keyword_ext, "extern", Token(Token::Type::ext))

SIMPLE_TOKEN_TEST(parse_alpha_identifier, "foobar", Identifier("foobar"))
SIMPLE_TOKEN_TEST(parse_alnum_identifier, "f00b4r", Identifier("f00b4r"))

SIMPLE_TOKEN_TEST(parse_unregistered_character, "<",
                  Token(static_cast<Token::Type>('<'))
)

