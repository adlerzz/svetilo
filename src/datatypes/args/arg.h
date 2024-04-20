#pragma once
#include "../datatypes.h"
#include "../../strmanip/strmanip.h"

struct Arg {
    virtual void fromStrings(Strings args) = 0;
};

struct ArgTime: public Arg {
    STime *time;

    void fromStrings(Strings args);
    ~ArgTime();
};

struct ArgAlarm: public Arg {
    STime *time;
    bool once;
    SDate *date;
    SWeekdayPattern *wp;
    std::string *modeId;
    std::string *alarmId;
    void fromStrings(Strings args);
    ~ArgAlarm();
};

struct ArgDate: public Arg {
    SDate *date;
    void fromStrings(Strings args);
};

struct ArgMode: public Arg {
    std::string *modeId;
    SMode mode;
    void fromStrings(Strings args);
};

class BaseArgFactory {};

template < class Derived>
class ArgFactory: public BaseArgFactory {
public:
    virtual Arg* create() {
        return new Derived();
    }
};

const ArgFactory<ArgMode> argModeFactory;
const ArgFactory<ArgAlarm> argAlarmFactory;