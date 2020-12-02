#include "backend.hpp"

namespace ci
{
    namespace backend
    {
        ci::message::MessageHandler* Backend::messageHandler = new ci::message::MessageHandler();

        ci::message::MessageHandler* Backend::getMessageHandler()
        {
            return messageHandler;
        }

        void Backend::addMessageListener(ci::message::IMessageListener* listener)
        {

        }
    }
} // namespace ci
