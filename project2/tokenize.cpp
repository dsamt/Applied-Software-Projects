#include "tokenize.hpp"
#include <cctype>

#include <iostream>

bool isBreak(char c) {
	return c == OPEN || c == CLOSE || c == COMMENT || (isspace(c) != 0) || (isprint(c) == 0);
}


TokenSequenceType tokenize(std::istream & seq){
  TokenSequenceType tokens;
  std::string symbol;

  for (char in = seq.get(); !seq.eof(); in = seq.get()) {
	  if (isBreak(in)) {
		  if (symbol.length() > 0) {
			  tokens.push_back(symbol);
			  symbol = "";
		  }
		  if (in == COMMENT) {
			  while ((in = seq.get()) != '\n' && !seq.eof()) {
				  //reads to end of comment
			  }
		  }
		  else if (in == OPEN || in == CLOSE) {
			  tokens.push_back(std::string(1, in));
		  }
	  }
	  else {
		  symbol.push_back(in);
	  }
  }

  if (symbol.length() > 0) {
	  tokens.push_back(symbol);
  }

  return tokens;
}
/*
Expression buildAST(TokenSequenceType & token) {

}
*/

