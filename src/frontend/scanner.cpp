#include "scanner.hpp"

namespace ci
{
    namespace frontend
    {
        Token Scanner::currentToken()
        {
            return curToken;
        }

        Token Scanner::nextToken() throw()
        {
            curToken = extractToken();
            return curToken;
        }

        char Scanner::currentChar() throw()
        {
            return source->currentChar();
        }

        char Scanner::nextChar() throw()
        {
            return source->nextChar();
        }
    } // namespace frontend
} // namespace ci
