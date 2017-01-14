#pragma once

#include "number.hpp"

#include <cstring>

inline KaleidescopeLang::AST::Number::Number(double value) : value(value)
{}

KaleidescopeLang::AST::Number::UniqueIdentifier KaleidescopeLang::AST::Number::get_unique_identifier()
{
  static_assert(sizeof(value) == sizeof(UniqueIdentifier),
                "value is memcpy'd into the return value");

  UniqueIdentifier ret;
  memcpy(&ret, &value, sizeof(UniqueIdentifier));
  return ret;
}
