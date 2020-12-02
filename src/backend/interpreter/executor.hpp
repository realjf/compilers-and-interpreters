#pragma once

#include "../../message/message.hpp"
#include "../../intermediate/icode.hpp"
#include "../../intermediate/symtab.hpp"
#include "../backend.hpp"
#include "summaryMessage.hpp"
#include <chrono>

using namespace std;

namespace ci
{
    namespace backend
    {
        namespace interpreter
        {
            class Executor : public Backend
            {
            public:
                Executor() : Backend(){};
                void process(ci::intermediate::ICode *iCode, ci::intermediate::SymTab *symTab) throw();
            };
        } // namespace interpreter
    }     // namespace backend
} // namespace ci
