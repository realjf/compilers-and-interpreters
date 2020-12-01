#pragma once
#include "message.hpp"

class MessageListener
{
public:
    virtual void messageReceived(Message* message);
};