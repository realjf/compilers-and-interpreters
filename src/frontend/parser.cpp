#include "parser.hpp"

namespace ci
{
    namespace frontend
    {
        ci::intermediate::SymTab *Parser::symTab = nullptr;
        ci::message::MessageHandler* Parser::messageHandle = new ci::message::MessageHandler();

        Token Parser::currentToken()
        {
            return scanner->currentToken();
        }

        Token Parser::nextToken()
        {
            return scanner->nextToken();
        }

        void Parser::addMessageListener(ci::message::IMessageListener *listener)
        {
            messageHandle->addListener(listener);
        }

        void Parser::removeMessageListener(ci::message::IMessageListener *listener)
        {
        }

        void Parser::sendMessage(ci::message::Message *message)
        {
        }

        ci::intermediate::ICode *Parser::getICode()
        {
            return iCode;
        }

        ci::intermediate::SymTab *Parser::getSymTab()
        {
            return symTab;
        }
    } // namespace frontend
} // namespace ci
