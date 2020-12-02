#pragma once

#include "../scanner.hpp"
#include "../eofToken.hpp"

namespace ci
{
    namespace frontend
    {
        namespace pascal
        {
            class PascalScanner : public Scanner
            {
            public:
                PascalScanner(Source *source) : Scanner(source)
                {
                }

            protected:
                Token extractToken() throw()
                {
                    Token *token;
                    char curChar = currentChar();

                    // construct the next token. the current character determines the token type
                    if (curChar == EOF)
                    {
                        token = new EofToken(source);
                    }
                    else
                    {
                        token = new Token(source);
                    }

                    return *token;
                }
            };
        } // namespace pascal
    }     // namespace frontend
} // namespace ci
