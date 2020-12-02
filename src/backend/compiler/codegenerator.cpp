#include "codegenerator.hpp"

namespace ci
{
    namespace backend
    {
        namespace compiler
        {
            void CodeGenerator::process(ci::intermediate::ICode *iCode, ci::intermediate::SymTab *symTab) throw()
            {
                auto startTime = chrono::steady_clock::now();
                auto elapsedTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - startTime);
                int instructionCount = 0;

                SummaryMessage* msg = new SummaryMessage(ci::message::MessageType::COMPILER_SUMMARY, instructionCount, elapsedTime);
                
                // send the compiler summary message
                messageHandler->sendMessage(msg);
            }

        } // namespace compiler
    }     // namespace backend
} // namespace ci
