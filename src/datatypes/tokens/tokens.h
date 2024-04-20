#pragma once
#include <string>
#include "../args/arg.h"

using namespace std;

enum Operation {
    NOOP,
    NEW_TIME,
    SHOW_TIME,
    NEW_ALARM,
    SHOW_ALARM,
    DEL_ALARM,
    NEW_DATE,
    SHOW_DATE,
    NEW_MODE,
    SHOW_MODE,
    DEL_MODE
};

struct Token {
    string token;
    Operation operation;
    BaseArgFactory argFactory;
};

struct TokenMap {
    int size;
    Token *tokens;

    TokenMap(const Token tokens[], int size);
    ~TokenMap();
    Token& getToken(string &token) const;
};

const Token NoopToken{"", Operation::NOOP, BaseArgFactory()};

const Token tokens[] = {
    { "NEW TIME",   Operation::NEW_TIME,   ArgFactory<ArgTime>()  },
    { "SHOW TIME",  Operation::SHOW_TIME,  ArgFactory<ArgTime>()  },
    { "NEW ALARM",  Operation::NEW_TIME,   ArgFactory<ArgAlarm>() },
    { "SHOW ALARM", Operation::SHOW_ALARM, ArgFactory<ArgAlarm>() },
    { "DEL ALARM",  Operation::DEL_ALARM,  ArgFactory<ArgAlarm>() },
    { "NEW DATE",   Operation::NEW_DATE,   ArgFactory<ArgDate>()  },
    { "SHOW DATE",  Operation::SHOW_DATE,  ArgFactory<ArgDate>()  },
    { "NEW MODE",   Operation::NEW_MODE,   ArgFactory<ArgMode>()  },
    { "SHOW MODE",  Operation::SHOW_MODE,  ArgFactory<ArgMode>()  },
    { "DEL MODE",   Operation::DEL_MODE,   ArgFactory<ArgMode>()  }
};

const TokenMap tokenMap(tokens, sizeof(tokens)/sizeof(tokens[0]));