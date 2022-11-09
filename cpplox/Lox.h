#pragma once
#include <string>

class Lox
{
public:
	static int main(int argc, char *argv[]);
protected:
private:
	static void runFile(std::string path);
	static void runPrompt();
	static void run(std::string source);
};

