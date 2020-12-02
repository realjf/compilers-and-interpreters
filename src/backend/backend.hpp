#pragma once

#include "../message/messageHandler.hpp"
#include "../intermediate/icode.hpp"
#include "../intermediate/symtab.hpp"
#include "../message/messageListener.hpp"

namespace ci
{
    namespace backend
    {
        class IBackend
        {
        public:
            virtual void process(ci::intermediate::ICode *iCode, ci::intermediate::SymTab *symTab) throw() = 0;
            virtual ci::message::MessageHandler* getMessageHandler() = 0;
        };

        class Backend : public IBackend
        {
        public:
            virtual void process(ci::intermediate::ICode *iCode, ci::intermediate::SymTab *symTab) throw();
            void addMessageListener(ci::message::IMessageListener* listener);
            ci::message::MessageHandler* getMessageHandler();

        protected:
            static ci::message::MessageHandler* messageHandler;

        protected:
            ci::intermediate::SymTab *symTab;
            ci::intermediate::ICode *iCode;
        };
    } // namespace backend

} // namespace ci
