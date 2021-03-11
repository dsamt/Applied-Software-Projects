// Starter code -- unit tests for Exercise-04
// Do not remove any of these tests. 
// It is a good idea to practice adding some new tests.
#define CATCH_CONFIG_MAIN 
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "MyVector.h"

TEST_CASE( "Test the constructor, size, and empty with an int type.", "[MyVector]" ) {

    MyVector<int> vec;
  
    REQUIRE( vec.size() == 0 );
    REQUIRE( vec.empty() == true );
}

TEST_CASE( "Test the constructor, size, and empty with a double type.", "[MyVector]" ) {

    MyVector<double> vec;
  
    REQUIRE( vec.size() == 0 );
    REQUIRE( vec.empty() == true );
}

TEST_CASE( "Test push_back method.", "[MyVector]" ) {

    MyVector<int> vec;
  
    REQUIRE( vec.size() == 0 );
    REQUIRE( vec.empty() == true );

    vec.push_back(42);

    REQUIRE( vec.size() == 1 );
    REQUIRE( vec.empty() == false );

    vec.push_back(3574);

    REQUIRE( vec.size() == 2 );
    REQUIRE( vec.empty() == false );
}

TEST_CASE( "Test at method.", "[MyVector]" ) {

    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(12);
    vec.push_back(8);
    vec.push_back(-40);

    REQUIRE( vec.at(0) == 1 );
    REQUIRE( vec.at(1) == 12 );
    REQUIRE( vec.at(2) == 8 );
    REQUIRE( vec.at(3) == -40 );

    vec.at(2) = 3;
    REQUIRE( vec.at(2) == 3 );
}

TEST_CASE( "Test value sematics", "[MyVector]" ) {

    MyVector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(12);
    vec1.push_back(8);
    vec1.push_back(-40);
	
    // test copy constructor
    MyVector<int> vec2 = vec1;
  
    REQUIRE( vec2.at(0) == 1 );
    REQUIRE( vec2.at(1) == 12 );
    REQUIRE( vec2.at(2) == 8 );
    REQUIRE( vec2.at(3) == -40 );
	
    // test assignment operator
   
	MyVector<int> vec3;
    vec3 = vec1;
  
    REQUIRE( vec3.at(0) == 1 );
    REQUIRE( vec3.at(1) == 12 );
    REQUIRE( vec3.at(2) == 8 );
    REQUIRE( vec3.at(3) == -40 );
	
    // test self assignment
    vec3 = vec3;
  
    REQUIRE( vec3.at(0) == 1 );
    REQUIRE( vec3.at(1) == 12 );
    REQUIRE( vec3.at(2) == 8 );
    REQUIRE( vec3.at(3) == -40 );
}

TEST_CASE("Additional Tests", "[MyVector]") {
	MyVector<float> vec1;

	REQUIRE(vec1.empty() == true);
	REQUIRE(vec1.size() == 0);

	vec1.push_back(3.3);
	REQUIRE(vec1.at(0) == 3.3f);
	vec1.push_back(2.7);
	vec1.push_back(55.2);
	vec1.push_back(25.3);
	REQUIRE(vec1.at(1) == 2.7f);
	REQUIRE(vec1.at(2) == 55.2f);
	REQUIRE(vec1.at(3) == 25.3f);

	// test copy constructor
	MyVector<float> vec2 = vec1;

	REQUIRE(vec2.at(0) == 3.3f);
	REQUIRE(vec2.at(1) == 2.7f);
	REQUIRE(vec2.at(2) == 55.2f);
	REQUIRE(vec2.at(3) == 25.3f);

	// test assignment operator

	MyVector<float> vec3;
	vec3 = vec1;

	REQUIRE(vec3.at(0) == 3.3f);
	REQUIRE(vec3.at(1) == 2.7f);
	REQUIRE(vec3.at(2) == 55.2f);
	REQUIRE(vec3.at(3) == 25.3f);
	
	//invalid index
	MyVector<int> vec;

	REQUIRE(vec.empty() == true);
	REQUIRE(vec.size() == 0);

	vec.push_back(5);
	vec.push_back(10);
	vec.push_back(9);

	REQUIRE(vec.at(0) == 5);
	REQUIRE(vec.at(1) == 10);
	REQUIRE(vec.at(2) == 9);
	REQUIRE(vec.at(3) == 0);
}
