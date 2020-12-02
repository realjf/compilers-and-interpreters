#include "backendFactory.hpp"

namespace ci
{
    namespace backend
    {
        Backend *BackendFactory::createBackend(string operation) throw()
        {
            if (strcasecmp(operation.c_str(), "compile"))
            {
                return new ci::backend::compiler::CodeGenerator();
            }
            else if (strcasecmp(operation.c_str(), "execute"))
            {
                return new Executor();
            }
            else
            {
                throw "Backend factory: Invalid operation '" + operation + "'";
            }
        }
    } // namespace backend
} // namespace ci
