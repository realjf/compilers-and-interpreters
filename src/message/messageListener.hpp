#pragma once
#include "message.hpp"

namespace ci
{
    namespace message
    {
        class IMessageListener
        {
        public:
            virtual void messageReceived(Message* message) = 0;
        };
    } // namespace message
} // namespace ci
