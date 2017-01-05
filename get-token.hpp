#pragma once

#include "token.hpp"

namespace KaleidescopeLang
{

Token *get_token(const char *buffer, size_t *tok_end);

}

