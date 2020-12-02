#pragma once

#include "../../message/message.hpp"
#include "../../message/messageType.hpp"
#include <chrono>
#include <string>

using namespace std;

namespace ci {
    namespace backend {
        namespace interpreter {
            class SummaryMessage : public ci::message::Message
            {
            public:
                explicit SummaryMessage(ci::message::MessageType type, int executionCount, int runtimeErrors, chrono::seconds elapsedTime) : ci::message::Message(type){
                    this->executionCount = executionCount;
                    this->runtimeErrors = runtimeErrors;
                    this->elapsedTime = elapsedTime;
                }

                inline string toString(){
                    char* str;
                    sprintf(str, "\n%20d statements executed\n%20d runtime errors\n%20.2f seconds total execution\n", executionCount, runtimeErrors, elapsedTime.count());

                    return str;
                }
            
            private:
                int executionCount;
                int runtimeErrors;
                chrono::seconds elapsedTime;
            };
        }
    }
}

