//
// Created by cherez on 5/19/19.
//
#include "lexer.h"

using namespace std;

Lexer::Lexer(shared_ptr<istream> s) {
    stream = s;
}

Token* Lexer::next() {
    skip:
    if (stream->eof()) return nullptr;
    char value;
    stream->get(value);
    switch(value) {
        case ' ':
        case '\r':
        case '\t':
            goto skip;
        default:
            buffer.push_back(value);
            return identifier();
    }
}

Identifier* Lexer::identifier() {
    auto ret = new Identifier;
    read:
    if (stream->eof()) {
        delete ret;
        return nullptr;
    }
    char value;
    stream->get(value);
    switch(value) {
        case ' ':
        case '\r':
        case '\t':
            ret->identifier = buffer;
            buffer.clear();
            return ret;
        default:
            buffer.push_back(value);
            goto read;
    }
}