#include "message.hpp"

namespace ci
{
    namespace message
    {
        Message::Message(MessageType type, array<void *, 3> body)
        {
            this->type = type;
            this->body = body;
        }

        MessageType Message::getType()
        {
            return this->type;
        }

        array<void *, 3> Message::getBody()
        {
            return body;
        }
    } // namespace message
} // namespace ci