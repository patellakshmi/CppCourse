//
// Created by Lakshmi S Patel on 17/05/21.
//

#ifndef CPPCOURSE_GRAPH_H
#define CPPCOURSE_GRAPH_H

#include <iostream>
#include <set>
using namespace std;

class Graph{

protected:
    set<int> *adj;
    int V;
public:
    Graph(int V){
        this->V = V;
        adj = new set<int>[V];
    }

    virtual void addEdge(int u, int v) {};

    int getTotalVertex(){
        return V;
    }

    set<int> getAdjList(int vertex){
        if( vertex < V ) {
            return adj[vertex];
        }
        throw "Invalid index";
    }

    void print(){
        for(int i = 0; i < V; i++){
            cout<< i<< ":-> ";
            for(auto a: adj[i]){
                cout<< " "<< a;
            }
            cout<< endl;
        }
    }

};

#endif //CPPCOURSE_GRAPH_H
