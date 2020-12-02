#pragma once

#include "./frontend/parser.hpp"
#include "./frontend/source.hpp"
#include "./backend/backend.hpp"
#include "./intermediate/icode.hpp"
#include "./intermediate/symtab.hpp"
#include "./frontend/frontendFactory.hpp"
#include "./backend/backendFactory.hpp"
#include "./cmd/sourceMessageListener.hpp"
#include "./cmd/parserMessageListener.hpp"
#include "./cmd/backendMessageListener.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Pascal
 * Compile or interpret a Pascal source program.
 */
class Pascal
{
public:
    Pascal(string operation, string filePath, string flags){
        try{
            bool intermediate = flags.find('r') != string::npos;
            bool xref = flags.find('x') != string::npos;

            source = new Source(new fstream::open());
            source->addMessageListener(new SourceMessageListener());

            parser = FrontendFactory::createParser("Pascal", "top-down", source);
            parser->addMessageListener(new ParserMessageListener());

            backend = BackendFactory::createBackend(operation);
            backend->addMessageListener(new BackendMessageListener());

            parser->parse();
            source->close();

            iCode = parser->getICode();
            symTab = parser->getSymTab();
        
            backend->process(iCode, symTab);
        }catch(const exception &e){
            cout << "****** Internal translator error. *******" << endl;
            cout << e.what() << endl;
        }
    }

private:
    Parser* parser;
    Source* source;
    ICode* iCode;
    SymTab* symTab;
    Backend* backend;
};


