#pragma once
#include <string>

using namespace std;

int parseInt(const string &str);
int parseInt(char ch);
string toUpperCase(string &str);
bool equalsIC(string &a, string &b);

struct Strings {
    string *strings;
    int size;

    Strings();
    void set(int size, string *strings);
    ~Strings();

};

void parseCommandString(string &str, string &operation, Strings &args);
