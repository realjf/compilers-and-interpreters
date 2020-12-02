#pragma once

#include "../message/messageListener.hpp"
#include "../message/message.hpp"
#include "../message/messageType.hpp"
#include <string>
#include <array>
#include <iostream>

using namespace std;

#define SOURCE_LINE_FORMAT = "%03d %s";

namespace ci
{
    namespace cmd
    {
        class SourceMessageListener : public ci::message::IMessageListener
        {
        public:
            void messageReceived(ci::message::Message* message)
            {
                ci::message::MessageType type = message->getType();

                switch (type)
                {
                case ci::message::SOURCE_LINE:
                {
                    int lineNumber = static_cast<int>(get<0>(body));
                    string lineText = static_cast<string>(get<1>(body));
                    cout << sprintf(SOURCE_LINE_FORMAT, lineNumber, lineText) << endl;
                    break;
                }
                }
            }
        };
    } // namespace cmd
} // namespace ci
