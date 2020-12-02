#include "executor.hpp"

namespace ci
{
    namespace backend
    {
        namespace interpreter
        {
            void Executor::process(ci::intermediate::ICode *iCode, ci::intermediate::SymTab *symTab) throw()
            {
                auto startTime = chrono::steady_clock::now();
                auto elapsedTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - startTime);
                int executionCount = 0;
                int runtimeErrors = 0;

                SummaryMessage* msg = new SummaryMessage(ci::message::MessageType::COMPILER_SUMMARY, executionCount, runtimeErrors, elapsedTime);
                
                // send the interpreter summary message
                messageHandler->sendMessage(msg);
            }
        } // namespace interpreter
    }     // namespace backend
} // namespace ci
