//
// Created by Lakshmi S Patel on 18/05/21.
//

#ifndef CPPCOURSE_DIRECTEDGRAPH_H
#define CPPCOURSE_DIRECTEDGRAPH_H

#include "Graph.h"
#include <iostream>
#include <set>
using namespace std;

class DirectedGraph : protected Graph{

public:
    DirectedGraph(int V):Graph(V){
    }

    void addEdge(int u, int v){
        adj[u].insert(v);
    }

};

#endif //CPPCOURSE_DIRECTEDGRAPH_H
