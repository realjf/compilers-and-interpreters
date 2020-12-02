#pragma once

#include <string>
#include "parser.hpp"
#include "source.hpp"
#include "scanner.hpp"
#include "./pascal/pascalScanner.hpp"
#include "./pascal/pascalParserTD.hpp"
#ifdef __LINUX__
#include <strings.h>
#endif
#include <string.h>
#include <exception>

using namespace std;

namespace ci
{
    namespace frontend
    {
        class FrontendFactory
        {
        public:
            static Parser *createParser(string language, string type, Source *source) throw()
            {
                if (strcasecmp(language.c_str(), "Pascal") && type.compare("top-down"))
                {
                    Scanner *scanner = new PascalScanner(source);
                    return new PascalParserTD(scanner);
                }
                else if (!strcasecmp(language.c_str(), "Pascal"))
                {
                    throw "Parser factory: Invalid language '" + language + "'";
                }
                else
                {
                    throw "Parser factory: Invalid type '" + type + "'";
                }
            }
        };
    } // namespace frontend
} // namespace ci
