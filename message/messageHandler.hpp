#pragma once

#include "message.hpp"
#include "messageListener.hpp"
#include <vector>

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
        this->listeners = std::vector<MessageListener*>();
    }

    void addListener(MessageListener* listener);
    void removeListener(MessageListener* listener);
    void sendMessage(Message* message);
    void notifyListeners();

private:
    Message* message;
    std::vector<MessageListener*> listeners;


};
