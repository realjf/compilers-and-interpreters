#pragma once

#include "token.hpp"
#include "source.hpp"

/**
 * Scanner
 * A language-independent framework class. This virtual scanner class
 * will be implemented by language-specific subclasses.
 */
class Scanner
{
public:
    Scanner(Source* source){
        this->source = source;
    }
    Token currentToken();
    Token nextToken() throw();
    char currentChar() throw();
    char nextChar() throw();

protected:
    virtual Token extractToken() throw();

protected:
    Source* source;

private:
    Token currentToken;
};
