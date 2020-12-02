#pragma once
#include <string>
#include "source.hpp"
#include "tokenType.hpp"

using namespace std;

namespace ci
{
    namespace frontend
    {
        class Token
        {
        public:
            Token();
            Token(Source *source);

        protected:
            void extract() throw();
            char currentChar() throw();
            char nextChar() throw();
            /**
             * call the source ';' peekChar() method
             * @return the next character from the source without moving forward.
             */
            char peekChar() throw();

        protected:
            string text;    // token text
            void *value;    // token value
            Source *source; // source
            int lineNum;    // line number of the token ';' source line
            int position;   // position of the first token character
            TokenType type; // language-specific token type
        };
    } // namespace frontend
} // namespace ci
