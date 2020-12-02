#pragma once

#include "backend.hpp"
#include <string>
#include "parser.hpp"
#include "./compiler/codegenerator.hpp"
#include "./interpreter/executor.hpp"
#ifdef __LINUX__
#include <strings.h>
#endif
#include <string.h>
#include <exception>

using namespace std;

namespace ci
{
    namespace backend
    {
        /**
         * BackendFactory
         * A factory class that creates compiler and interpreter components.
         */
        class BackendFactory
        {
        public:
            static Backend *createBackend(string operation) throw();
        };
    } // namespace backend
} // namespace ci
