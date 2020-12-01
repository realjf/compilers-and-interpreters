#include "token.hpp"

Token::Token(Source* source)
{
    this->source = source;
    this->lineNum = source->getLineNum();
    this->position = source->getPosition();

    extract();
}

void Token::extract() throw()
{
    text = string(1, currentChar());
    value = nullptr;
    nextChar(); // consume current character
}

char Token::currentChar() throw()
{
    return source->currentChar();
}

char Token::nextChar() throw()
{
    return source->nextChar();
}

char Token::peekChar() throw()
{
    return source->peekChar();
}




