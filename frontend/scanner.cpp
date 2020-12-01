#include "scanner.hpp"

Token Scanner::currentToken()
{
    return currentToken;
}

Token Scanner::nextToken() throw()
{
    currentToken = extractToken();
    return currentToken;
}

char Scanner::currentChar() throw()
{
    return source->currentChar();
}

char Scanner::nextChar() throw()
{
    return source->nextChar();
}

