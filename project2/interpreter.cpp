#include "interpreter.hpp"

// system includes
#include <stack>
#include <stdexcept>
#include <iostream>

// module includes
#include "tokenize.hpp"
#include "expression.hpp"
#include "environment.hpp"
#include "interpreter_semantic_error.hpp"

Interpreter::Interpreter() {
	this->env = Environment();
	//this->ast = Expression();
}

bool Interpreter::parse(std::istream & expression) noexcept{
  // TODO: implement this function
  // return true if input is valid. otherwise, return false.
	this->InterpreterError = "";
	try {
		TokenSequenceType tokens = tokenize(expression);

		if (tokens.empty()) {
			InterpreterError = "Error: blank";
			return false;
		}
		if (tokens.front() != "(") {
			InterpreterError = "Error: program does not start with '('";
			return false;
		}
		ast = read_from_tokens(tokens);
		if (!tokens.empty()) {
			InterpreterError = "Error: Invalid extra input";
			return false;
		}
	}
	catch (std::logic_error & error) {
		InterpreterError = error.what();
		return false;
	}
	for (int i = 0; i < ast.tail.size(); i++) {
		//std::cout << ast.tail[i] << std::endl;
	}
	return true;
};

Expression Interpreter::eval(){
  // TODO: implement this function
	return this->ast.eval(this->env);
}

std::string Interpreter::getError() const {
	return this->InterpreterError;
}


Expression Interpreter::read_from_tokens(TokenSequenceType & tokens) {
	if (tokens.empty()) {
		throw std::logic_error("unexpected EOF1");
	}
		std::string token = tokens.front();
		if (token == "(") {
			tokens.pop_front();
			if (tokens.empty()) {
				throw std::logic_error("unexpected EOF2");
			}
			Expression out = read_from_tokens(tokens);
			while (tokens.front() != ")" && !tokens.empty()) {
				out.addTail(read_from_tokens(tokens));
			}

			if (tokens.empty()) {
				throw std::logic_error("unexpected EOF3");
			}
			tokens.pop_front();
			return out;
		}
	
	Expression out = tokenToExpression(tokens.front());
	tokens.pop_front();
	return out;

	
}