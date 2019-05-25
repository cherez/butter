//
// Created by cherez on 5/19/19.
//

#ifndef BUTTER_LEXER_H
#define BUTTER_LEXER_H

#include <iostream>
#include <memory>
#include <string>

struct Token {};

struct Identifier : Token {
    std::string identifier;
};

class Lexer {
    std::shared_ptr<std::istream> stream;
    std::string buffer;

    Identifier* identifier();

public:
    Lexer(std::shared_ptr<std::istream>);
    Token* next();
};

#endif //BUTTER_LEXER_H
