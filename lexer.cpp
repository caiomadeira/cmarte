#include "common.hpp"
#include<string>

enum Token {
    tok_eof = -1,
    tok_def = -2,
    tok_extern = -3,
    tok_identifier = -4,
    tok_number = -5
};

static std::string identifier_str;
static double num_val;

static int gettoken() {
    static int last_char = ' ';
    while(isspace(last_char)) {
        last_char = getchar();
    }

    if (isalpha(last_char)) {
        identifier_str = last_char;
        while (isalnum((last_char = getchar()))) {
            identifier_str += last_char;
        }

        if (identifier_str == "func") return tok_def;
        if (identifier_str == "extern") return tok_extern;
        return tok_identifier;
    }
}