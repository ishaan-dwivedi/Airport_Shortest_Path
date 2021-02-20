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

// Dijkstra Test Cases
/*
TEST_CASE("Test Dijkstra", "") {
  
  SECTION("Finds the shortest distance on a simple graph with all weights being 1") {
    Graph g_(true, false);
    string filename = "simpledata.txt";
    Graph::ParseData(filename, g_);
    Graph place_holder(true, false);

    // All sources
    Vertex source_0 = "0";
    Vertex source_1 = "1";
    Vertex source_2 = "2";
    Vertex source_3 = "3";
    Vertex source_4 = "4";

    // All Destinations
    Vertex destination_0 = "0";
    Vertex destination_1 = "1";
    Vertex destination_2 = "2";
    Vertex destination_3 = "3";
    Vertex destination_4 = "4";

    // Map containing the shortest paths from source 0 to each vertex
    std::map<Vertex, int> distance_dictionary_source_0 = place_holder.getShortestPath(g_, source_0);

    REQUIRE(distance_dictionary_source_0[destination_0] == 0);
    REQUIRE(distance_dictionary_source_0[destination_1] == 1);
    REQUIRE(distance_dictionary_source_0[destination_2] == 1);
    REQUIRE(distance_dictionary_source_0[destination_3] == 1);
    REQUIRE(distance_dictionary_source_0[destination_4] == 2);

    // Map containing the shortest paths from source 1 to each vertex
    std::map<Vertex, int> distance_dictionary_source_1 = place_holder.getShortestPath(g_, source_1);

    REQUIRE(distance_dictionary_source_1[destination_0] == 1);
    REQUIRE(distance_dictionary_source_1[destination_1] == 0);
    REQUIRE(distance_dictionary_source_1[destination_2] == 1);
    REQUIRE(distance_dictionary_source_1[destination_3] == 2);
    REQUIRE(distance_dictionary_source_1[destination_4] == 2);

    // Map containing the shortest paths from source 2 to each vertex
    std::map<Vertex, int> distance_dictionary_source_2 = place_holder.getShortestPath(g_, source_2);

    REQUIRE(distance_dictionary_source_2[destination_0] == 1);
    REQUIRE(distance_dictionary_source_2[destination_1] == 1);
    REQUIRE(distance_dictionary_source_2[destination_2] == 0);
    REQUIRE(distance_dictionary_source_2[destination_3] == 2);
    REQUIRE(distance_dictionary_source_2[destination_4] == 1);

    // Map containing the shortest paths from source 3 to each vertex
    std::map<Vertex, int> distance_dictionary_source_3 = place_holder.getShortestPath(g_, source_3);

    REQUIRE(distance_dictionary_source_3[destination_0] == 1);
    REQUIRE(distance_dictionary_source_3[destination_1] == 2);
    REQUIRE(distance_dictionary_source_3[destination_2] == 2);
    REQUIRE(distance_dictionary_source_3[destination_3] == 0);
    REQUIRE(distance_dictionary_source_3[destination_4] == 3);

    // Map containing the shortest paths from source 4 to each vertex
    std::map<Vertex, int> distance_dictionary_source_4 = place_holder.getShortestPath(g_, source_4);

    REQUIRE(distance_dictionary_source_4[destination_0] == 2);
    REQUIRE(distance_dictionary_source_4[destination_1] == 2);
    REQUIRE(distance_dictionary_source_4[destination_2] == 1);
    REQUIRE(distance_dictionary_source_4[destination_3] == 3);
    REQUIRE(distance_dictionary_source_4[destination_4] == 0);

  } 
  

  SECTION("Finds the shortest distance on a simple graph with weights being non-negative int and variable") {
    Graph g_(true, false);
    string filename = "simpledata.txt";
    Graph::ParseData(filename, g_);
    Graph place_holder(true, false);

    // All sources
    Vertex source_0 = "0";
    Vertex source_1 = "1";
    Vertex source_2 = "2";
    Vertex source_3 = "3";
    Vertex source_4 = "4";

    // All Destinations
    Vertex destination_0 = "0";
    Vertex destination_1 = "1";
    Vertex destination_2 = "2";
    Vertex destination_3 = "3";
    Vertex destination_4 = "4";

    // Set edges to different weights
    g_.setEdgeWeight(source_0, destination_1, 5);
    g_.setEdgeWeight(source_0, destination_2, 5);
    g_.setEdgeWeight(source_0, destination_3, 4);
    g_.setEdgeWeight(source_1, destination_2, 15);
    g_.setEdgeWeight(source_2, destination_4, 8);


    // Map containing the shortest paths from source 0 to each vertex
    std::map<Vertex, int> distance_dictionary_source_0 = place_holder.getShortestPath(g_, source_0);

    REQUIRE(distance_dictionary_source_0[destination_0] == 0);
    REQUIRE(distance_dictionary_source_0[destination_1] == 5);
    REQUIRE(distance_dictionary_source_0[destination_2] == 5);
    REQUIRE(distance_dictionary_source_0[destination_3] == 4);
    REQUIRE(distance_dictionary_source_0[destination_4] == 13);

    // Map containing the shortest paths from source 1 to each vertex
    std::map<Vertex, int> distance_dictionary_source_1 = place_holder.getShortestPath(g_, source_1);

    REQUIRE(distance_dictionary_source_1[destination_0] == 5);
    REQUIRE(distance_dictionary_source_1[destination_1] == 0);
    REQUIRE(distance_dictionary_source_1[destination_2] == 10);
    REQUIRE(distance_dictionary_source_1[destination_3] == 9);
    REQUIRE(distance_dictionary_source_1[destination_4] == 18);

    // Map containing the shortest paths from source 2 to each vertex
    std::map<Vertex, int> distance_dictionary_source_2 = place_holder.getShortestPath(g_, source_2);

    REQUIRE(distance_dictionary_source_2[destination_0] == 5);
    REQUIRE(distance_dictionary_source_2[destination_1] == 10);
    REQUIRE(distance_dictionary_source_2[destination_2] == 0);
    REQUIRE(distance_dictionary_source_2[destination_3] == 9);
    REQUIRE(distance_dictionary_source_2[destination_4] == 8);

    // Map containing the shortest paths from source 3 to each vertex
    std::map<Vertex, int> distance_dictionary_source_3 = place_holder.getShortestPath(g_, source_3);

    REQUIRE(distance_dictionary_source_3[destination_0] == 4);
    REQUIRE(distance_dictionary_source_3[destination_1] == 9);
    REQUIRE(distance_dictionary_source_3[destination_2] == 9);
    REQUIRE(distance_dictionary_source_3[destination_3] == 0);
    REQUIRE(distance_dictionary_source_3[destination_4] == 17);

    // Map containing the shortest paths from source 4 to each vertex
    std::map<Vertex, int> distance_dictionary_source_4 = place_holder.getShortestPath(g_, source_4);

    REQUIRE(distance_dictionary_source_4[destination_0] == 13);
    REQUIRE(distance_dictionary_source_4[destination_1] == 18);
    REQUIRE(distance_dictionary_source_4[destination_2] == 8);
    REQUIRE(distance_dictionary_source_4[destination_3] == 17);
    REQUIRE(distance_dictionary_source_4[destination_4] == 0);

  } 
  
}
*/