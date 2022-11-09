#include "Lox.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

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
	}
}

void Lox::run(std::string source)
{

}