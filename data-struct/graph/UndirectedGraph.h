//
// Created by Lakshmi S Patel on 18/05/21.
//

#ifndef CPPCOURSE_UNDIRECTEDGRAPH_H
#define CPPCOURSE_UNDIRECTEDGRAPH_H


#include "Graph.h"
#include <iostream>
#include <set>
using namespace std;

class UndirectedGraph : protected Graph{

public:
    UndirectedGraph(int V):Graph(V){
    }

    void addEdge(int u, int v){
        adj[u].insert(v);
        adj[v].insert(u);
    }

};

#endif //CPPCOURSE_UNDIRECTEDGRAPH_H
