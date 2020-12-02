#include "messageHandler.hpp"

namespace ci
{
    namespace message
    {
        void MessageHandler::addListener(IMessageListener *listener)
        {
            listeners[listener] = true;
        }

        void MessageHandler::removeListener(IMessageListener *listener)
        {
            listeners.erase(listener);
        }

        void MessageHandler::sendMessage(Message* message)
        {
            this->message = message;
            notifyListeners();
        }

        void MessageHandler::notifyListeners()
        {
            for (auto listener : listeners)
            {
                listener.first->messageReceived(message);
            }
        }

    } // namespace message
} // namespace ci
