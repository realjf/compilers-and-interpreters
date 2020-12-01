#pragma once

#include "token.hpp"
#include "scanner.hpp"
#include "../message/messageHandler.hpp"
#include "../message/messageListener.hpp"
#include "../message/message.hpp"
#include "../intermediate/icode.hpp"
#include "../intermediate/symtab.hpp"

/**
 * Parser
 * A language-independent framework class. This virtual parser class 
 * will be implemented by language-specific subclasses.
 */
class Parser
{
public:
    Parser();
    /**
     * parse a source program and generate the intermediate code and the
     * symbol table. To be implemented by a language-specific parser subclass.
     */
    virtual void parse();
    /**
     * Return the number of syntax errors found by the parser.
     * To be implemented by a language-specific parser subclass.
     * @return the error count.
     */
    virtual int getErrorCount();
    Token currentToken();

    /**
     * Call the scanner&apos;s nextToken() method.
     * @return the next token.
     */
    Token nextToken();
    
    void addMessageListener(MessageListener* listener);
    void removeMessageListener(MessageListener* listener);
    void sendMessage(Message* message);

protected:
    Parser(Scanner* scanner){
        this->scanner = scanner;
        this->iCode = nullptr;
    }

protected:
    ICode* iCode; // intermediate code generated by this parser
    static SymTab symTab; // generated symbol table

    Scanner* scanner; // scanner used with this parser

    static MessageHandler* messageHandle; // message handler delegate

private:

};
