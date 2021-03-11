#include "environment.hpp"

#include <cassert>
#include <cmath>
#include <functional>

#include "interpreter_semantic_error.hpp"


Procedure makeProcedure(Expression exp) {
	return[exp](Environment &env, std::vector<Expression> tail) {
		return exp;
	};
}

Environment::Environment(){
	this->envmap = std::map<Symbol, Procedure>();

	this->definition("pi", Expression(atan2(0, -1)));
	this->definition("not", Not());
	this->definition("and", Bool(std::logical_and<bool>()));
	this->definition("or", Bool(std::logical_or<bool>()));
	this->definition("<", Compare(std::less<double>()));
	this->definition("<=", Compare(std::less_equal<double>()));
	this->definition(">", Compare(std::greater<double>()));
	this->definition(">=", Compare(std::greater_equal<double>()));
	this->definition("=", Compare(std::equal_to<double>()));
	this->definition("+", Add(std::plus<double>()));
	this->definition("-", Subtract());
	this->definition("*", Mult(std::multiplies<double>()));
	this->definition("/", Divide());
	this->definition("log10", Log());
	this->definition("pow", Pow());
	this->definition("begin", Begin());
	this->definition("define", Define());
	this->definition("if", If());


}

void Environment::definition(Symbol symbol, Procedure proc) {
	if (this->envmap.count(symbol) != 0u) {
		throw InterpreterSemanticError("Error: symbol \"" + symbol + "\"" + "is being redefined");
	}
	this->envmap[symbol] = proc;
}

void Environment::definition(Symbol symbol, Expression exp) {
	this->definition(symbol, makeProcedure(exp));
}


Procedure Environment::get(Symbol s) {
	if (this->envmap.count(s) != 0u) {
		return this->envmap[s];
	}
	throw InterpreterSemanticError("Error: symbol \"" + s + "\"" + " not defined");
}










/*
Expression &Environment::procNot(const Expression & exp) {

}

Expression &Environment::procAnd(const Expression & exp) {

}

Expression &Environment::procOr(const Expression & exp) {

}

Expression &Environment::procLessThan(const Expression & exp) {

}

Expression &Environment::procLessThanOE(const Expression & exp) {

}

Expression &Environment::procGreatThan(const Expression & exp) {

}

Expression &Environment::procGreatThanOE(const Expression & exp) {

}

Expression &Environment::procEqual(const Expression & exp) {

}

Expression &Environment::procPlus(const Expression & exp) {

}

Expression &Environment::procMinus(const Expression & exp) {

}

Expression &Environment::procMul(const Expression & exp) {

}

Expression &Environment::procDiv(const Expression & exp) {

}

Expression &Environment::procLog(const Expression & exp) {

}

Expression &Environment::procPow(const Expression & exp) {

}
*/