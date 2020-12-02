#pragma once

#include "messageType.hpp"
#include <array>

namespace ci
{
    namespace message
    {
        class IMessage
        {
        };

        /**
         * Message
         * Message format.
         */
        class Message : public IMessage
        {
        public:
            Message(MessageType type)
            {
                this->type = type;
            }

            MessageType getType();

        private:
            MessageType type;
        };
    } // namespace message
} // namespace ci
