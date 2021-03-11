#include <cstdlib>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstring>


#include "tokenize.hpp"
#include "expression.hpp"
#include "environment.hpp"
#include "interpreter.hpp"
#include "interpreter_semantic_error.hpp"
#include <functional>



int program(Interpreter &interpret, std::istream &stream) {
	if (!interpret.parse(stream)) {
		std::cerr << interpret.getError() << std::endl;
		return EXIT_FAILURE;
	}
	try {
		std::cout << interpret.eval() << std::endl;
	}
	catch (InterpreterSemanticError error) {
		std::cerr << error.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


int main(int argc, char **argv)
{
	if (argc == 1) { // REPL
		Interpreter interpret = Interpreter();
		std::string line;
		std::cout << "slisp> ";

		while (std::getline(std::cin, line)) {
			if (!line.empty()) {
				std::stringstream stream(line);
				if (program(interpret, stream) == EXIT_FAILURE) {
					interpret = Interpreter();
				}
			}
			std::cout << "slisp> ";
		}
		return EXIT_SUCCESS;
	}
	if (argc == 3 && std::strcmp(argv[1], "-e") == 0) {
		Interpreter interpret = Interpreter();
		std::stringstream stream(argv[2]);
		return program(interpret, stream);
	}
	if (argc == 2 && std::string(argv[1]).substr(0,2) == "-e") {
		std::stringstream stream(std::string(argv[1]).substr(2));
		Interpreter interpret = Interpreter();
		return program(interpret, stream);
	}
	if (argc == 2) {
		std::ifstream file(argv[1]);
		if (!file.is_open()) {
			std::cerr << "Error: Could not open file" << std::endl;
		}
		Interpreter interpret = Interpreter();
		return program(interpret, file);
	}
	std::cerr << "Error: Wrong number of outputs" << std::endl;
    return EXIT_FAILURE;
}
