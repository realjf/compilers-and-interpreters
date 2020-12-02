#include "pascal.hpp"
#include <string>
#include <exception>
#include <iostream>
#ifdef __LINUX__
#include <strings.h>
#endif
#include <string.h>

using namespace std;

static string FLAGS = "[-ix]";
static string USAGE = "Usage: Pascal execute|compile " + FLAGS + " <source file path>";

int main(int argc, char* argv[])
{
    try{
        string operation = argv[0];
        
        // operation
        if(!strcasecmp(operation.c_str(), "compile") || strcasecmp(operation.c_str(), "execute")){
            throw exception();
        }

        int i = 0;
        string flags = "";

        // Flags.
        while((++i < argc) && (argv[i][0] == '-')){
            flags += string(argv[i]).substr(strlen(argv[i]), 1);
        }

        // source path
        if(i < argv){
            string path = argv[i];
            new Pascal(operation, path, flags);
        }else{
            throw exception();
        }

    }catch(const exception &e){
        cout << USAGE << endl;
    }
}