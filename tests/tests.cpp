#include "../catch/catch.hpp"
#include "../graph.h"
#include "../edge.h"
#include <string>
#include<iostream>
#include <fstream>
#include <map>
using namespace std;


// Sanity Check
TEST_CASE("Test to test if running make test works", "") {
  int x = 9;
  int y = 10;
  
  REQUIRE( x < y );
}