#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

// system includes
#include <map>
#include <functional>

// module includes
#include "expression.hpp"
#include "Procedure.hpp"

//typedef Expression(*Procedure)(const std::vector<Atom> & args);


class Environment{
public:
	//using standard fucntion to define a procedure in order to make it callable for functors instead of a plain function pointer
  Environment();
  void definition(Symbol symbol, Expression exp);
  void definition(Symbol symbol, Procedure proc);
  Procedure get(Symbol s);
  

private:

  // Environment is a mapping from symbols to expressions or procedures
  enum EnvResultType {ExpressionType, ProcedureType};
  struct EnvResult{
    EnvResultType type;
    Expression exp;
    Procedure proc;
  };

  //new definition of envmap in order to use the callable standard function procedure for functors
  std::map<Symbol, Procedure> envmap;
 // Procedure makeProcedure(Expression exp);





  /*
  Expression &procNot(const Expression & exp);
  Expression &procAnd(const Expression & exp);
  Expression &procOr(const Expression & exp);
  Expression &procLessThan(const Expression & exp);
  Expression &procLessThanOE(const Expression & exp);
  Expression &procGreatThan(const Expression & exp);
  Expression &procGreatThanOE(const Expression & exp);
  Expression &procEqual(const Expression & exp);
  Expression &procPlus(const Expression & exp);
  Expression &procMinus(const Expression & exp);
  Expression &procMul(const Expression & exp);
  Expression &procDiv(const Expression & exp);
  Expression &procLog(const Expression & exp);
  Expression &procPow(const Expression & exp);
  */
};
#endif
