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
  
  // Washington Dulles: Latitude:  38.94449997  Longitude: -77.45580292
  // Chicago O'hare:    Lattitude: 41.9786      Longitude: -87.9048
  const double IAD_LAT = 38.94449997;
  const double IAD_LONG = -77.45580292;
  const double ORD_LAT = 41.9786;
  const double ORD_LONG = -87.9048;

  // Calculated Answer
  Graph place_holder(true);
  double ans = place_holder.calculateDistance(IAD_LAT, IAD_LONG, ORD_LAT, ORD_LONG);

  
  REQUIRE( ans == IAD_ORD );
}