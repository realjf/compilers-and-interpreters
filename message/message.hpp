#pragma once

#include "messageType.hpp"

/**
 * Message
 * Message format.
 */
class Message
{
public:
    Message();
    Message(MessageType type, void* body)
    {
        this->type = type;
        this->body = body;
    }

private:
    void* body;
    MessageType type;
};
