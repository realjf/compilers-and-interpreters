#pragma once

#include <string>
#include <fstream>
using namespace std;

/**
 * Source
 * The framework class that represents the source program.
 */
class Source
{
public:
    Source(ifstream* reader) throw() {
        this->lineNum = 0;
        this->currentPos = -2; // set to -2 to read the first source line
        this->reader = reader;
    }
    char currentChar() throw();
    char nextChar() throw();
    char peekChar() throw();
    void close() throw();
    int getLineNum();
    int getPosition();

private:
    void readLine() throw();

public:
    static char EOL; // end-of-line character

private:
    ifstream* reader; // reader for the source program
    string line; // source line
    int lineNum;    // current source line number
    int currentPos; // current source line position
};
