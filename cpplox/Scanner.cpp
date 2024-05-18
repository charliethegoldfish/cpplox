#include "Scanner.h"
#include "Lox.h"

Scanner::Scanner(std::string source) : source(source)
{
	start = 0;
	current = 0;
	line = 1;
}

std::vector<Token> Scanner::scanTokens()
{
	while (!isAtEnd())
	{
		// We are at the beginning of the next lexeme
		start = current;
		scanToken();
	}

	//TODO: #TokenLiteral swap string literal variable for literal union
	Token newToken = Token(ENDOF, "", "", line);
	tokens.push_back(newToken);
	
	return tokens;
}

void Scanner::scanToken()
{
	char c = advance();

	switch (c)
	{
	case '(':
		addToken(LEFT_PAREN);
		break;
	case ')':
		addToken(RIGHT_PAREN);
		break;
	case '{':
		addToken(LEFT_BRACE);
		break;
	case '}':
		addToken(RIGHT_BRACE);
		break;
	case ',':
		addToken(COMMA);
		break;
	case '.':
		addToken(DOT);
		break;
	case '-':
		addToken(MINUS);
		break;
	case '+':
		addToken(PLUS);
		break;
	case ';':
		addToken(SEMICOLON);
		break;
	case '*':
		addToken(STAR);
		break;
	case '!':
		addToken(match('=') ? BANG_EQUAL : BANG);
		break;
	case '=':
		addToken(match('=') ? EQUAL_EQUAL : EQUAL);
		break;
	case '<':
		addToken(match('=') ? LESS_EQUAL : LESS);
		break;
	case '>':
		addToken(match('=') ? GREAT_EQUAL : GREATER);
		break;
	case '/':
		if (match('/'))
		{
			while (peek() != '\n' && !isAtEnd())
			{
				advance();
			}
		}
		else
		{
			addToken(SLASH);
		}
		break;

	case ' ':
	case '\r':
	case '\t':
		// Ignore whitespace
		break;

	case '\n':
		line++;
		break;

	default:
		Lox::error(line, "Unexpected character.");
		break;
	}
}

bool Scanner::match(char expected)
{
	if(isAtEnd()) return false;
	if(source[current] != expected) return false;

	current++;
	return true;
}

char Scanner::peek()
{
	if(isAtEnd()) return '\0';
	return source[current];
}

bool Scanner::isAtEnd()
{
	return current >= source.length();
}

char Scanner::advance()
{
	return source[current++];
}

void Scanner::addToken(TokenType type)
{
	addToken(type, "");
}

void Scanner::addToken(TokenType type, std::string literal)
{
	int length = current - start;
	std::string text = source.substr(start, length);
	tokens.push_back(Token(type, text, literal, line));
}