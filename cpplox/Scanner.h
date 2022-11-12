#pragma once

#include "Token.h"
#include <vector>

class Scanner
{
private:
	const std::string source;
	std::vector<Token> tokens;
	int start;
	int current;
	int line;

	bool isAtEnd();
	char advance();
	void addToken(TokenType type);
	void addToken(TokenType type, std::string literal);

	void scanToken();

public:
	Scanner(std::string source);
	std::vector<Token> scanTokens();
};

