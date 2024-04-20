#include "arg.h"

STime *parseTime(string &arg){
    const int hours = parseInt(arg.substr(0,2));
    const int minutes = parseInt(arg.substr(3,2));
    STime *result = new STime();
    result->hours = hours;
    result->minutes = minutes;
    return result;
}

SDate *parseDate(string &arg){
    const int years = parseInt(arg.substr(0,4));
    const int months = parseInt(arg.substr(5,2));
    const int days = parseInt(arg.substr(8,2));
    SDate *result = new SDate();
    result->years = years;
    result->months = months;
    result->days = days;
    return result;
}

bool isWP(string &str){
    return !isdigit(str[0]);
}

SWeekdayPattern* parseWP(string &arg){
    SWeekdayPattern *result = new SWeekdayPattern();

    if(arg == "md"){
        arg = "*****--";        
    }
    if(arg == "we"){
        arg = "-----**";
    }

    result->mon = (arg[0] == '*');
    result->tue = (arg[1] == '*');
    result->wed = (arg[2] == '*');
    result->thu = (arg[3] == '*');
    result->fri = (arg[4] == '*');
    result->sat = (arg[5] == '*');
    result->sun = (arg[6] == '*');

    return result;
}

void ArgTime::fromStrings(Strings args){
    this->time = parseTime(args.strings[0]);
    if(isWP(args.strings[1])){
        this->time = NULL;
        // this->
    }
}

ArgTime::~ArgTime() {
    delete this->time;
}

void ArgAlarm::fromStrings(Strings args){
    this->time = parseTime(args.strings[0]);
    if(args.size <= 1){
        return;
    }
    if(isWP(args.strings[1])){
        this->date = NULL;
        this->wp = parseWP(args.strings[1]);
    } else {
        this->date = parseDate(args.strings[1]);
        this->wp = NULL;
    }

}

ArgAlarm::~ArgAlarm(){
    delete this->time;
}


void ArgDate::fromStrings(Strings str){

}

void ArgMode::fromStrings(Strings str){
    
}