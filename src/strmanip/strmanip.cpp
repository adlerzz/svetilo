#include "strmanip.h"

Strings::Strings(){
    this->size = 0;
    this->strings = NULL;
}

void Strings::set(int size, string *strings){
    this->size = size;
    this->strings = new string[size];
    for(int i=0; i<size; i++){
        this->strings[i] = strings[i];
    }
}

Strings::~Strings(){
    delete[] this->strings;
}

int parseInt(const string &str){
    return stoi(str);
}

int parseInt(char ch){
    return isdigit(ch) ? (int)(ch - '0') : -1;
}

bool whileSpace(string str, int pos) {
    return pos < str.length() && isspace(str[pos]);
}

bool untilSpace(string str, int pos) {
    return pos < str.length() && !isspace(str[pos]);
}

string extractWord(int &pointer, string str) {
    for(; whileSpace(str, pointer); pointer++);
    int init = pointer;
    for(; untilSpace(str, pointer); pointer++);
    return str.substr(init, pointer - init);
}

void parseCommandString(string &str, string &operation, Strings &args){
    int pointer = 0;
    string opcode = extractWord(pointer, str);
    string option = extractWord(pointer, str);
    operation = opcode + " " + option;
    
    const int MAX_POOL_SIZE = 5;
    string pool_args[MAX_POOL_SIZE];

    int pool_size = 0;
    for(; pool_size < MAX_POOL_SIZE; pool_size++){
        string arg = extractWord(pointer, str);
        if(arg.length() == 0){
            break;
        }
        pool_args[pool_size] = arg;
    }
    args.set(pool_size, pool_args);
}

string toUpperCase(string &str){
    auto result = string(str);
    for(auto it = result.begin(); it != result.end(); ++it){
        *it = toupper(*it);
    }
    return result;
}

bool equalsIC(string &a, string &b){
    return toUpperCase(a) == toUpperCase(b);
}