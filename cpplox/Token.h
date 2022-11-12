#pragma once

#include <string>

typedef std::string TokenType;

// Single-character tokens
const TokenType LEFT_PAREN = "LEFT_PAREN";
const TokenType RIGHT_PAREN = "RIGHT_PAREN";
const TokenType LEFT_BRACE = "LEFT_BRACE";
const TokenType RIGHT_BRACE = "RIGHT_BRACE";
const TokenType COMMA = "COMMA";
const TokenType DOT = "DOT";
const TokenType MINUS = "MINUS";
const TokenType PLUS = "PLUS";
const TokenType SEMICOLON = "SEMICOLON";
const TokenType SLASH = "SLASH";
const TokenType STAR = "STAR";

// One or two character tokens
const TokenType BANG = "BANG";
const TokenType BANG_EQUAL = "BANG_EQUAL";
const TokenType EQUAL = "EQUAL";
const TokenType EQUAL_EQUAL = "EQUAL_EQUAL";
const TokenType GREATER = "GREATER";
const TokenType GREAT_EQUAL = "GREAT_EQUAL";
const TokenType LESS = "LESS";
const TokenType LESS_EQUAL = "LESS_EQUAL";

// Keywords
const TokenType AND = "AND";
const TokenType CLASS = "CLASS";
const TokenType ELSE = "ELSE";
const TokenType FALSE = "FALSE";
const TokenType FUN = "FUN";
const TokenType FOR = "FOR";
const TokenType IF = "IF";
const TokenType NIL = "NIL";
const TokenType OR = "OR";
const TokenType PRINT = "PRINT";
const TokenType RETURN = "RETURN";
const TokenType SUPER = "SUPER";
const TokenType THIS = "THIS";
const TokenType TRUE = "TRUE";
const TokenType VAR = "VAR";
const TokenType WHILE = "WHILE";

const TokenType ENDOF = "EOF";

//TODO: #TokenLiteral setup union as literal
//union Literal
//{
//	double number;
//	std::string string;
//};

class Token
{
private:
	const TokenType type;
	const std::string lexeme;
	//TODO: #TokenLiteral swap string for literal union
	//const Literal literal;
	const std::string literal;
	const int line;

public:
	//TODO: #TokenLiteral swap string literal variable for literal union
	Token(TokenType type, std::string lexeme, std::string literal, int line);
	std::string toString();
};

