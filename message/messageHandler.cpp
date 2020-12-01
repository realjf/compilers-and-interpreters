#include "messageHandler.hpp"


void MessageHandler::addListener(MessageListener* listener)
{
    listeners.push_back(listener);
}

void MessageHandler::removeListener(MessageListener* listener)
{
    listeners.front();
}

void MessageHandler::sendMessage(Message* message)
{
    this->message = message;
    notifyListeners();
}

void MessageHandler::notifyListeners()
{
    for(MessageListener* listener : listeners){
        listener->messageReceived(message);
    }
}
