#include "expression.hpp"

#include <cmath>
#include <limits>
#include <cctype>

// system includes
#include <sstream>
#include "interpreter_semantic_error.hpp"
#include "environment.hpp"


Expression::Expression(bool tf) {
	this->head.type = BooleanType;
	this->head.value.bool_value = tf;
}

Expression::Expression(double num) {
	this->head.type = NumberType;
	this->head.value.num_value = num;
}

Expression::Expression(const std::string & sym) {
	this->head.type = SymbolType;
	this->head.value.sym_value = sym;
}

bool Expression::operator==(const Expression & exp) const noexcept {
	return ((this->head.type == exp.head.type) &&
		((this->head.value.bool_value == exp.head.value.bool_value) || (this->head.value.num_value == exp.head.value.num_value) || (this->head.value.sym_value == exp.head.value.sym_value))
		&& (this->tail == exp.tail));
}

std::string Expression::_string() const {
	std::string result;
	if (this->head.type == NoneType) {
		result = "()";
	}
	else if (this->head.type == BooleanType) {
		if (this->head.value.bool_value) {
			result = "True";
		}
		else {
			result = "False";
		}
	}
	else if (this->head.type == NumberType) {
		std::stringstream s;
		s << this->head.value.num_value;
		result = s.str();
	}
	else if (this->head.type == SymbolType) {
		result = this->head.value.sym_value;
	}
	return result;
}



bool token_to_atom(const std::string & token, Atom & atom){
  // TODO: implement this function
  // return true if it a token is valid. otherwise, return false.
	bool flag = false;
	if (token == "True") {
		atom.type = BooleanType;
		atom.value.bool_value = true;
		flag = true;
	}
	else if (token == "False") {
		atom.type = BooleanType;
		atom.value.bool_value = false;
		flag = true;
	}
	else {
		try {
			std::size_t last;
			double dub = std::stod(token, &last);
			if (last != token.size()) {
				return false;
			}
			atom.type = NumberType;
			atom.value.num_value = dub;
			return true;
		}
		catch (std::invalid_argument & e) {
			atom.type = SymbolType;
			atom.value.sym_value = token;
			return true;
		}
	}
  return flag;
}

void Expression::addTail(Expression exp) {
	if (head.type != SymbolType) {
		throw std::logic_error("Error: arguments only pertain to symbols");
	}

	tail.push_back(exp);
}

Expression tokenToExpression(const std::string & token) {
	Expression result;
	if (token == "True") {
		result = Expression(true);
	}
	else if (token == "False") {
		result = Expression(false);
	}
	else {
		try {
			std::size_t last;
			double dub = std::stod(token, &last);
			if (last != token.size()) {
				throw std::logic_error("symbol not a digit");
			}
			return Expression(dub);
		}
		catch (std::invalid_argument & e) {
			return Expression(token);
		}
	}
	return result;
}

Symbol Expression::getSymbol() const {
	if (this->head.type != SymbolType) {
		throw InterpreterSemanticError("Error: expected expression to be of type Symbol");
	}
	return this->head.value.sym_value;
}

Number Expression::getNumber() const {
	if (this->head.type != NumberType) {
		throw InterpreterSemanticError(
			"Error: expected expression to evaluate to Number");
	}
	return this->head.value.num_value;
}

Number Expression::getNumber(Environment &env) const {
	return this->eval(env).getNumber();
}

Boolean Expression::getBool() const {
	if (this->head.type != BooleanType) {
		throw InterpreterSemanticError(
			"Error: expected expression to evaluate to Bool");
	}
	return this->head.value.bool_value;
}

Boolean Expression::getBool(Environment &env) const {
	return this->eval(env).getBool();
}

Expression Expression::eval(Environment &env) const {
	if (this->head.type != SymbolType) {
		return *this;
	}

	return env.get(head.value.sym_value)(env, this->tail);
}

std::vector<Expression> Expression::getTail() const {
	return this->tail;
}

std::ostream & operator<<(std::ostream & out, const Expression & exp) {
	out << "(" << exp._string();
	for (const auto &t : exp.getTail()) {
		out << t;
	}
	out << ")";
	return out;
}