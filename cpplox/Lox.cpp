#include "Lox.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Scanner.h"

bool Lox::hadError = false;

int Lox::main(int argc, char* argv[])
{
	if (argc == 1) {
		runPrompt();
	}
	else if (argc == 2) {
		runFile(argv[1]);
	}
	else {
		printf("Usage: %s <script>\n", argv[0]);
		return 1;
	}

	return 0;
}

void Lox::runFile(std::string path)
{
	std::string output;
	std::string fileData;
	std::ifstream file(path);

	while (std::getline(file, output))
	{
		fileData.append(output);
	}

	run(fileData);

	if (Lox::hadError)
	{
		// TODO: Implement #ErrorHandling for exit here (pg 42)
	}
}

void Lox::runPrompt()
{
	while (1)
	{
		std::string line;
		std::cout << "> ";
		std::getline(std::cin, line);
		if (line[0] == '\0')
		{
			break;
		}
		run(line);
		Lox::hadError = false;
	}
}

void Lox::run(std::string source)
{
	// TODO: Implement function as per pg 41 once #Scanner is ready
	Scanner scanner = Scanner(source);
	std::vector<Token> tokens = scanner.scanTokens();

	// For now just print the tokens
	for (auto& token : tokens)
	{
		std::cout << token.toString() << std::endl;
	}
}

void Lox::error(int line, std::string message)
{
	report(line, "", message);
}

void Lox::report(int line, std::string where, std::string message)
{
	// TODO: Implement #ErrorHandling for this message - error print rather than normal print (pg 41)
	// printf("[line %i] Error %s: %s", line, where, message);
	std::cout << "[line " << line << "] Error " << where << ": " << message << std::endl;
	Lox::hadError = true;
}