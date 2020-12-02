#pragma once

#include "../../message/message.hpp"
#include "../parser.hpp"
#include "../scanner.hpp"
#include "../token.hpp"
#include "../eofToken.hpp"
#include <chrono>
using namespace std;

namespace ci
{
    namespace frontend
    {
        namespace pascal
        {

            /**
             * PascalParserTD
             * The top-down Pascal parser.
             */
            class PascalParserTD : public Parser
            {
            public:
                PascalParserTD(Scanner *scanner) : Parser(scanner)
                {
                }

                void parse() throw()
                {
                    Token token;
                    auto startTime = chrono::steady_clock::now();

                    while (typeid(token = nextToken()) != typeid(EofToken))
                    {
                        // send the parser summary message.
                        auto elapsedTime = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - startTime);
                        void *numberArray[] = {

                            getErrorCount(),
                            elapsedTime.count(),
                        };
                        elapsedTime.count();

                        messageHandler->sendMessage(new ci::message::Message(PARSER_SUMMARY, numberArray));
                    }
                }

                /**
                 * return the number of syntax errors found by the parser
                 */
                int getErrorCount()
                {
                    return 0;
                }
            };
        } // namespace pascal
    }     // namespace frontend
} // namespace ci
