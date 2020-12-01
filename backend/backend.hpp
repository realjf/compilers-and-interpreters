#pragma once

#include "../message/messageHandler.hpp"
#include "../intermediate/icode.hpp"
#include "../intermediate/symtab.hpp"

class Backend
{
public:
    virtual void process(ICode* iCode, SymTab* symTab) throw();

protected:
    static MessageHandler* messageHandler;

protected:
    SymTab* symTab;
    ICode* iCode;

};
