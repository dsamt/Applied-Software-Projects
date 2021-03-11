#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include <cassert>    
#include <cstdlib>

TEST_CASE("multimap unit test1", "[multimap]") {
	std::multimap<std::string, std::string> m;	
	REQUIRE(m.size() == 0);
	
	m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));
	REQUIRE(m.size() == 1);

}

TEST_CASE("Test the constructor, empty, size, and clear", "[multimap]") {
	std::multimap<std::string, std::string> m;
	REQUIRE(m.size() == 0);
	REQUIRE(m.empty());


	m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));
	REQUIRE(m.size() == 1);
	m.insert(std::pair<std::string, std::string>("R", "B"));
	REQUIRE(m.size() == 2);
	m.insert(std::pair<std::string, std::string>("e", "c"));
	REQUIRE(m.size() == 3);
	m.insert(std::pair<std::string, std::string>("d", "v"));
	REQUIRE(m.size() == 4);
	m.clear();
	REQUIRE(m.size() == 0);
	REQUIRE(m.empty());
}

TEST_CASE("Test insert and count", "[multimap]") {
	std::multimap<std::string, std::string> m;
	REQUIRE(m.size() == 0);
	REQUIRE(m.empty());


	m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));
	REQUIRE(m.size() == 1);
	REQUIRE(m.count("Ross") == 1);
	m.insert(std::pair<std::string, std::string>("R", "B"));
	REQUIRE(m.size() == 2);
	REQUIRE(m.count("R") == 1);
	m.insert(std::pair<std::string, std::string>("e", "c"));
	REQUIRE(m.size() == 3);
	REQUIRE(m.count("e") == 1);
	m.insert(std::pair<std::string, std::string>("d", "v"));
	REQUIRE(m.size() == 4);
	REQUIRE(m.count("d") == 1);
	m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));
	REQUIRE(m.size() == 5);
	REQUIRE(m.count("Ross") == 2);
	m.clear();
	REQUIRE(m.size() == 0);
	REQUIRE(m.empty());
	REQUIRE(m.count("Ross") == 0);
}

TEST_CASE("Test erase and find", "[multimap]") {
	std::multimap<int, char> m = { {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'} };

	REQUIRE(m.size() == 6);
	REQUIRE_FALSE(m.empty());
	

	for (int i = 1; i <= 6; i++) {
		REQUIRE(m.count(i) == 1);
		auto search = m.find(i);
		if (search != m.end()) {
			search = m.erase(search);
		}
		REQUIRE(m.count(i) == 0);
	}
	REQUIRE(m.empty());
	REQUIRE(m.size() == 0);
}

TEST_CASE("Test assignment operator", "[multimap]") {
	std::multimap<int, char> m = { {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'} };

	REQUIRE(m.size() == 6);
	REQUIRE_FALSE(m.empty());

	for (int i = 1; i <= 6; i++) {
		REQUIRE(m.count(i) == 1);
	}

	std::multimap<int, char> m1;
	//perform deep copy using copy assignment operator
	m1 = m;

	for (int i = 1; i <= 6; i++) {
		REQUIRE(m1.count(i) == 1);
	}

	for (int i = 1; i <= 6; i++) {
		REQUIRE(m.count(i) == 1);
		auto search = m.find(i);
		if (search != m.end()) {
			search = m.erase(search);
		}
		REQUIRE(m.count(i) == 0);
	}
	REQUIRE(m.empty());
	REQUIRE(m.size() == 0);
	//make sure deep, copy holds when original is changed
	for (int i = 1; i <= 6; i++) {
		REQUIRE(m1.count(i) == 1);
	}

}