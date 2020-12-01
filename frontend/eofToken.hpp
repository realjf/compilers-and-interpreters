#pragma once

#include "token.hpp"

/**
 * EofToken
 * The generic end-of-file token
 */
class EofToken : public Token
{
public:
    EofToken(Source* source) : Token(source){};

protected:
    void extract(Source* source) throw();
};