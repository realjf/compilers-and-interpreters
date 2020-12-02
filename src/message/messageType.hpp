#pragma once

namespace ci
{
    namespace message
    {
        enum MessageType
        {
            SOURCE_LINE,
            SYNTAX_ERROR,
            PARSER_SUMMARY,
            INTERPETER_SUMMARY,
            COMPILER_SUMMARY,
            MISCELLANEOUS,
            TOKEN,
            ASSIGN,
            FETCH,
            BREAKPOINT,
            RUNTIME_ERROR,
            CALL,
            RETURN,
        };
    }
} // namespace ci
