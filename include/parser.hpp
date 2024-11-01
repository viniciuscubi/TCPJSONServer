#ifndef PARSER_HPP
#define PARSER_HPP

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>

class Parser{

    private:
        std::string str_;
        rapidjson::Document document_;
        int parseError_ = 0;

    public:
        Parser(const std::string &str);

        bool parse();
        int  getError();
        rapidjson::Value &getData();


};

#endif