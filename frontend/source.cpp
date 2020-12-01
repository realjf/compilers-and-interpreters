#include "source.hpp"
#include <exception>
#include <iostream>
using namespace std;

char Source::EOL = '\n';

char Source::currentChar() throw()
{
    // first time
    if(currentPos == -2){
        readLine();
        return nextChar();
    }

    // at end of file
    else if (line.data() == nullptr){
        return EOF;
    }

    // at end of line
    else if((currentPos == -1) || (currentPos == line.length())){
        return EOL;
    }

    // need to read next line
    else if(currentPos > line.length()){
        readLine();
        return nextChar();
    }

    // return the character at the current position
    else{
        return line.c_str()[currentPos];
    }
}

char Source::nextChar() throw()
{
    ++currentPos;
    return currentChar();
}

char Source::peekChar() throw()
{
    currentChar();
    if(line.data() == nullptr){
        return EOF;
    }

    int nextPos = currentPos + 1;
    return nextPos < line.length() ? line.c_str()[nextPos] : EOL;
}

void Source::readLine() throw()
{
    getline(*reader, line); // nullptr at the end of the source
    currentPos = -1;
    if(line.data() != nullptr){
        ++lineNum;
    }
}

void Source::close() throw()
{
    if(reader != nullptr){
        try{
            reader->close();
        }catch(exception &e){
            cerr << "close reader error: " << e.what() << endl;;
            throw e;
        }
    }
}

int Source::getLineNum()
{
    return lineNum;
}

int Source::getPosition()
{
    return currentPos;
}
