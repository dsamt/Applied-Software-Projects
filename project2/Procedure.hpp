#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

#include <functional>
#include <vector>
#include "expression.hpp"
class Environment;

typedef std::function<bool(bool, bool)> BoolFunction;
typedef std::function<double(double, double)> MultiuseFunction;
typedef std::function<bool(double, double)> CompareFunction;


typedef std::function<Expression(Environment &env, std::vector<Expression>)> Procedure;

struct Not {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Bool {
private:
	std::function<bool(bool, bool)> BoolFn;
public:
	Bool(BoolFunction fn);
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Compare {
private:
	CompareFunction CmpFn;
public:
	Compare(CompareFunction fn);
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Add {
private:
	MultiuseFunction AddFn;
public:
	Add(MultiuseFunction fn);
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Mult {
private:
	MultiuseFunction MultFn;
public:
	Mult(MultiuseFunction fn);
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Subtract {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Divide {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Begin {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct If {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Define {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Log {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

struct Pow {
	Expression operator()(Environment &env, std::vector<Expression> tail) const;
};

#endif