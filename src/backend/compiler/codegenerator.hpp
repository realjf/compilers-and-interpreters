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
        namespace compiler
        {
            class CodeGenerator : public Backend
            {
            public:
                CodeGenerator() : Backend(){};
                void process(ci::intermediate::ICode *iCode, ci::intermediate::SymTab *symTab) throw();
            };
        } // namespace compiler
    }     // namespace backend
} // namespace ci
