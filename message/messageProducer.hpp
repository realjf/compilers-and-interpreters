#pragma once

#include "messageListener.hpp"
#include "message.hpp"

class MessageProducer
{
public:
    virtual void addMessgeListenser(MessageListener* listener);
    virtual void removeMessageListener(MessageListener* listener);
    virtual void sendMessage(Message* message);
};
