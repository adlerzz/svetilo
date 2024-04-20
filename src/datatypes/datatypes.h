#pragma once
#include <string>
#include "../strmanip/strmanip.h"

enum Opcode {
    NEW,
    SHOW,
    DEL,
};

enum Option {
    TIME,
    DATE,
    ALARM,
    MODE,
};

template <typename T>
struct TokenValueEntry {
    string token;
    T value;
};

template <typename T>
struct TokenValueMap {
    int size;
    TokenValueEntry<T> *entries;

    TokenValueMap(const TokenValueEntry<T> entries[], int size){
        this->entries = const_cast<TokenValueEntry<T>*>(entries);
        this->size = size;    
    }

    ~TokenValueMap(){}

    T valueByToken(string &token) const {
        for(int i = 0; i < this->size; i++){
            if(equalsIC(this->entries[i].token, token)){
                return this->entries[i].value;
            }
        }
    }

    string tokenByValue( T &value) const {
        for(int i = 0; i < this->size; i++){
            if(this->entries[i].value == value){
                return this->entries[i].token;
            }
        }
    }

};

const TokenValueEntry<Opcode> opcodeTokens[] = {
    { "NEW",  Opcode::NEW },
    { "SHOW", Opcode::SHOW },
    { "DEL",  Opcode::DEL },
};
const TokenValueMap<Opcode> opcodeTokenMap(opcodeTokens, sizeof(opcodeTokens)/ sizeof(opcodeTokens[0]));

const TokenValueEntry<Option> optionTokens[] = {
    { "TIME",  Option::TIME },
    { "DATE",  Option::DATE },
    { "ALARM", Option::ALARM },
    { "MODE",  Option::MODE },
};
const TokenValueMap<Option> optionTokenMap(optionTokens, sizeof(optionTokens)/sizeof(optionTokens[0]));


struct STime {
    short hours;
    short minutes;
};

struct SDate {
    short years;
    short months;
    short days;
};

struct SWeekdayPattern {
    short mon;
    short tue;
    short wed;
    short thu;
    short fri;
    short sat;
    short sun;
};

struct SMode {
    short white;
    short yellow;
};