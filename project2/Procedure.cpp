#include "Procedure.hpp"
#include "environment.hpp"
#include "interpreter_semantic_error.hpp"
#include "expression.hpp"
#include <sstream>
#include <cmath>

enum _arity {Unary, Binary, Ternary, M_ary};

void errorCheck(std::size_t arguments, _arity ar) {
	if ((arguments == 1 && ar == Unary) || (arguments == 2 && ar == Binary) || (arguments == 3 && ar == Ternary) || (arguments >= 2 && ar == M_ary)) {
		return;
	}
	std::stringstream error;
	error << "Error: wrong _arity for " << arguments << "arguments";
	throw InterpreterSemanticError(error.str());
}

Expression Not::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, Unary);

	return Expression(!tail[0].getBool(env));
}

Bool::Bool(BoolFunction fn) {
	this->BoolFn = fn;
}

Expression Bool::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, M_ary);

	bool result = tail[0].head.value.bool_value;
	for (std::size_t i = 1; i < tail.size(); i++) {
		result = this->BoolFn(result, tail[i].getBool(env));
	}
	return Expression(result);
}

Compare::Compare(CompareFunction fn) {
	this->CmpFn = fn;
}

Expression Compare::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, Binary);

	return Expression(this->CmpFn(tail[0].getNumber(env), tail[1].getNumber(env)));
}

Add::Add(MultiuseFunction fn) {
	this->AddFn = fn;
}

Expression Add::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, M_ary);

	double result = tail[0].head.value.num_value;
	for (std::size_t i = 1; i < tail.size(); i++) {
		result = this->AddFn(result, tail[i].getNumber(env));
	}
	return Expression(result);
}

Mult::Mult(MultiuseFunction fn) {
	this->MultFn = fn;
}

Expression Mult::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, M_ary);

	double result = tail[0].head.value.num_value;
	for (std::size_t i = 1; i < tail.size(); i++) {
		result = this->MultFn(result, tail[i].getNumber(env));
	}
	return Expression(result);
}

Expression Subtract::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();

	if (nargs == 1) {
		return Expression(-1 * tail[0].getNumber(env));
	}
	errorCheck(nargs, Binary);
	return Expression(tail[0].getNumber(env) - tail[1].getNumber(env));
}

Expression Divide::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, Binary);

	return Expression(tail[0].getNumber(env) / tail[1].getNumber(env));
}

Expression Begin::operator()(Environment &env, std::vector<Expression> tail) const {
	Expression result;

	for (auto const &i : tail) {
		result = i.eval(env);
	}
	return Expression(result);
}

Expression If::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, Ternary);

	return tail[0].getBool(env) ? tail[1].eval(env) : tail[2].eval(env);
}

Expression Define::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, Binary);

	Expression result = tail[1].eval(env);

	env.definition(tail[0].getSymbol(), result);
	return result;
}

Expression Log::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, Unary);

	return Expression(log10(tail[0].getNumber(env)));
}

Expression Pow::operator()(Environment &env, std::vector<Expression> tail) const {
	std::size_t nargs = tail.size();
	errorCheck(nargs, Binary);

	return Expression(pow(tail[0].getNumber(env), tail[1].getNumber(env)));
}