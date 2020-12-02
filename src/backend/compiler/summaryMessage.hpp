#pragma once

#include "../../message/message.hpp"
#include "../../message/messageType.hpp"
#include <chrono>
#include <string>

using namespace std;

namespace ci {
    namespace backend {
        namespace compiler {
            class SummaryMessage : public ci::message::Message
            {
            public:
                explicit SummaryMessage(ci::message::MessageType type, int instructionCount, chrono::seconds elapsedTime) : ci::message::Message(type){
                    this->instructionCount = instructionCount;
                    this->elapsedTime = elapsedTime;
                }

                inline string toString(){
                    char* str;
                    sprintf(str, "\n%20d instructions generated\n%20.2f seconds total execution", instructionCount, elapsedTime.count());

                    return str;
                }
            
            private:
                int instructionCount;
                chrono::seconds elapsedTime;
            };
        }
    }
}

