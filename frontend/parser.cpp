#include "parser.hpp"

SymTab Parser::symTab = nullptr;
MessageHandler Parser::messageHandle = new MessageHandler();


Token Parser::currentToken()
{
    return scanner->currentToken();
}

Token Parser::nextToken()
{
    return scanner->nextToken();
}

void Parser::addMessageListener(MessageListener* listener)
{
    messageHandle->addListener(listener);
}

void Parser::removeMessageListener(MessageListener* listener)
{

}

void Parser::sendMessage(Message* message)
{

}
