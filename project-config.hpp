#pragma once

#include <string>

namespace KaleidescopeLang
{

class String : public std::string
{
public:
  String() : std::string() {}
  String(char c) : std::string(1, c) {}
};

}

