//
// Created by Lakshmi S Patel on 30/05/21.
//

#ifndef CPPCOURSE_LISTOFEDGEGRAPH_H
#define CPPCOURSE_LISTOFEDGEGRAPH_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class ListOfEdgeGraph{
public:
    int v;
    int e;
    vector<pair<int, pair<int,int>> edges;
    ListOfEdgeGraph(int v, int e){ this->v = v; this->e = e; }
    void addEdge(int u, int v, int w){ this->edges.push_back({w, {u, v}}); }
};

#endif //CPPCOURSE_LISTOFEDGEGRAPH_H
