#include "function.hpp"

KaleidescopeLang::AST::Prototype::Prototype(String name, std::vector<String> args)
  : name(name), args(args)
{
}
