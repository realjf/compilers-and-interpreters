#pragma once

#include <string>
#include "parser.hpp"
#include "source.hpp"
#include "scanner.hpp"

using namespace std;

class FrontendFactory
{
public:
    static Parser createParser(string language, string type, Source source) throw()
    {
        if(language.compare("Pascal") && type.compare("top-down")){
            Scanner scanner = new PascalScanner(source);
            return new ParcalParserTD(scanner);
        }
    }
};