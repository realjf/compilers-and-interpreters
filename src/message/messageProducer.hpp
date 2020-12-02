#pragma once

#include "messageListener.hpp"
#include "message.hpp"

namespace ci
{
    namespace message
    {
        class IMessageProducer
        {
        public:
            virtual void addMessageListenser(IMessageListener *listener) = 0;
            virtual void removeMessageListener(IMessageListener *listener) = 0;
            virtual void sendMessage(const Message &message) = 0;
        };
    } // namespace message
} // namespace ci
