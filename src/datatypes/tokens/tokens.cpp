#include "tokens.h"

TokenMap::TokenMap(const Token tokens[], int size){
    this->tokens = const_cast<Token*>(tokens);
    this->size = size;    
}

TokenMap::~TokenMap(){}

Token& TokenMap::getToken(string &token) const {
    for(int i = 0; i < this->size; i++){
        if(equalsIC(this->tokens[i].token, token)){
            return this->tokens[i];
        }
    }
    return const_cast<Token&>(NoopToken);
}

    /* string tokenByValue( T &value) const {
        for(int i = 0; i < this->size; i++){
            if(this->entries[i].value == value){
                return this->entries[i].token;
            }
        }
    }*/