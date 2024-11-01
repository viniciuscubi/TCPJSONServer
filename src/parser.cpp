#include "../include/parser.hpp"

Parser::Parser(const std::string &str) : str_(str){}

bool Parser::parse(){
    document_.Parse(str_.c_str());

    if(document_.HasParseError()){
        parseError_ = document_.GetParseError();

        return false;
    }

    return true;
}

int Parser::getError() {
    return parseError_;
}


rapidjson::Value& Parser::getData() {
    return document_;
}
