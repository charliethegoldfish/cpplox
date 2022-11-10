#pragma once

#include <string>

enum TokenType {
	// Single-character tokens
	LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

	// One or two character tokens
	BANG, BANG_EQUAL, EQUAL, EQUAL_EQUAL, GREATER, GREAT_EQUAL, LESS, LESS_EQUAL,

	// Literals
	IDENTIFIER, STRING, NUMBER,

	// Keywords
	AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR, PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

	ENDOF
};

union Literal
{
	double number;
	std::string string;
};

class Token
{
private:
	TokenType type;
	std::string lexeme;
	//const Literal literal;
	std::string literal;
	int line;

	Token(TokenType type, std::string lexeme, std::string literal, int line);

public:
	std::string toString();
};

