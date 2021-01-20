#include <iostream>
#include "graph.h"

int main() {

    // Make sure only one username shows in commit, not a duplicate
    // Added comment
    // Changed user email
    Graph g(true);
    Graph d(false);
    Graph::parseData("sample_airport_data.txt", g);
    std::cout << "Makefile works" << std::endl;
    return 0;
}