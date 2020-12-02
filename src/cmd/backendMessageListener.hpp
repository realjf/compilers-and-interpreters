#pragma once

#include "../message/messageListener.hpp"
#include "../message/message.hpp"
#include "../message/messageType.hpp"
#include <string>
#include <array>
#include <iostream>

namespace ci
{
    namespace cmd
    {
        class BackendMessageListener : public ci::message::IMessageListener
        {
        public:
            void messageReceived(const ci::message::Message &message)
            {
            }
        };
    } // namespace cmd
} // namespace ci
