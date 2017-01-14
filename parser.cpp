#include "parser.hpp"

#include "call.hpp"
#include "expression.hpp"
#include "log.hpp"
#include "number.hpp"
#include "function.hpp"
#include "get-token.hpp"
#include "variable.hpp"

namespace KaleidescopeLang
{

using AST::Expression;

struct ParseResult
{
  const Expression *expression;
  const Token *next_unconsumed_token;

  ParseResult(const Expression *e, const Token *t)
    : expression(e), next_unconsumed_token(t)
  {}
};

ParseResult parse_primary(const Token *tok)
{
  switch (tok->tag)
  {
  case Token::identifier:
    return parse_identifier(tok);
  case Token::number:
    return parse_number(static_cast<const Numeral *>(tok));

  }
}

ParseResult parse_expression(const Token *tok)
{
  return ParseResult(nullptr, nullptr);
}

ParseResult parse_number(const Numeral *numeral)
{
  return ParseResult(new AST::Number(numeral->value), numeral + 1);
}

ParseResult parse_identifier(const Token *tok)
{
  const Identifier *id = dynamic_cast<const Identifier *>(tok);
  ++tok;

  if (tok->tag != '(')
    return ParseResult(new AST::Variable(id->name), tok);
  else // function call
  {
    std::vector<const Expression *> args;
    while (true)
    {
      ++tok;
      ParseResult res = parse_expression(tok);
      args.push_back(res.expression);

      tok = res.next_unconsumed_token;
      if (tok->tag == ')')
      {
        ++tok;
        break;
      }
      else if (tok->tag != ',')
        log_error("Expected a ',' or ')' in argument list!");
    }
    return ParseResult(new AST::Call(lookup_function(id->name), args), tok);
  }
}

ParseResult parse_parens(const Token *tok)
{
  ++tok; // skip '('
  ParseResult inner = parse_expression(tok);
  
  tok = inner.next_unconsumed_token;
  if (tok->tag != ')')
    log_error("expected ')'");
  ++tok; // skip ')'

  return ParseResult(inner.expression, tok);
}

}
