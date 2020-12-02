#pragma once

#include "message.hpp"
#include "messageListener.hpp"
#include "messageProducer.hpp"
#include <map>

namespace ci
{
    namespace message
    {
        /**
         * MessageHandler
         * A helper class to which message producer classes delegate the task of
         * maintaining and notifying listeners.
         */
        class MessageHandler
        {
        public:
            MessageHandler()
            {
                this->listeners = std::map<IMessageListener *, bool>();
            }

            void addListener(IMessageListener *listener);
            void removeListener(IMessageListener *listener);
            void sendMessage(Message* message);
            void notifyListeners();

        private:
            Message* message;
            std::map<IMessageListener *, bool> listeners;
        };
    } // namespace message
} // namespace ci
