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

TEST_CASE("Test for calculating the distance given two map coordinates", "") {
  
  // Distance from Dulles airport in Washington DC to O'hare aiport in Chicago
  // Distance from Google Maps around 572.38 miles
  // https://www.distance.to/Dulles-International-Airport,VA,USA/OHare-Int'l-Airport,10000-W-O'Hare-Ave,Chicago,IL,60666,USA
  double IAD_ORD = 572.38;
  
  // Calculated Answer
  Graph place_holder(true);
  double ans = place_holder.calculateDistance(0, 0, 0, 0);

  
  REQUIRE( ans == IAD_ORD );
}