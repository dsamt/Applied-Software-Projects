#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <string>
#include <sstream>

#include "tokenize.hpp"

TEST_CASE("testing tokenize", "[tokenize]") {
	std::string program = "(begin (define r 10) (* pi (* r r)))";

	std::istringstream iss(program);

	TokenSequenceType tokens = tokenize(iss);

	REQUIRE(tokens.size() == 17);
	REQUIRE(tokens[0] == "(");
	REQUIRE(tokens[1] == "begin");
	REQUIRE(tokens[2] == "(");
	REQUIRE(tokens[3] == "define");
	REQUIRE(tokens[4] == "r");
	REQUIRE(tokens[5] == "10");
	REQUIRE(tokens[6] == ")");
	REQUIRE(tokens[7] == "(");
	REQUIRE(tokens[8] == "*");
	REQUIRE(tokens[9] == "pi");
	REQUIRE(tokens[10] == "(");
	REQUIRE(tokens[11] == "*");
	REQUIRE(tokens[12] == "r");
	REQUIRE(tokens[13] == "r");
	REQUIRE(tokens[14] == ")");
	REQUIRE(tokens[15] == ")");
	REQUIRE(tokens[16] == ")");
}
