#include <iostream>
#include <string>
#include "datatypes/datatypes.h"
#include "datatypes/tokens/tokens.h"
#include "datatypes/args/arg.h"
#include "strmanip/strmanip.h"

using namespace std;

struct Command{
    Opcode opcode;
    Option option;
    Token *operationToken;
    Arg *argValue;
};

Command parseCommand(string &opcode, string &option, Strings &args);
void showCommand(Command &command);

int main() {
    string testStrings[] = {
        " new  time  22:10 ",
        " show time ",
        " del  time",
        " new alarm 08:10 mf #default @routine",
        "show alarm",
        " del   alarm @traen"
        " show date",
        "  new   time   12:10   ",
        "new mode  #an 200:800",
        
    };
    
    for(string testString: testStrings){
        cout << "$\"" << testString << "\"" << endl;
        string opcode, option;
        string operation;
        Strings args;
        parseCommandString(testString, operation, args);
        Command command = parseCommand(opcode, option, args);
        showCommand(command);
        cout << endl;
    }
    return 0;
}

Command parseCommand(string &operation, Strings &args){
    Command result;
    result.operationToken = &tokenMap.getToken(operation);
    // result.argValue.set(args.size, args.strings);
    

    return result;
}

void showCommand(Command &command){
    cout << "# " << opcodeTokenMap.tokenByValue(command.opcode) << " + " << optionTokenMap.tokenByValue(command.option) << ", $a => [";
    /*
    for(int i=0; i < command.argValue.size; i++) {
       cout << " \"" << command.argValue.strings[i] << "\" " ;
    }
    */
    cout << "]" << endl;
     
}


