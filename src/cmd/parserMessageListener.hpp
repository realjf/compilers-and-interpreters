#pragma once

#include "../message/messageListener.hpp"
#include "../message/message.hpp"
#include "../message/messageType.hpp"
#include <string>
#include <iostream>
#include <array>

using namespace std;

#define PARSER_SUMMARY_FORMAT = "\n%,20d source lines.\n%,20d syntax errors.\n%,20.2f seconds total parsing time.\n";

namespace ci
{
    namespace cmd
    {
        class ParserMessageListener : public ci::message::IMessageListener
        {
        public:
            void messageReceived(ci::message::Message *message)
            {
                ci::message::MessageType type = message->getType();

                switch (type)
                {
                case ci::message::PARSER_SUMMARY:
                {
                    break;
                }
                }
            }
        };
    } // namespace cmd
} // namespace ci
