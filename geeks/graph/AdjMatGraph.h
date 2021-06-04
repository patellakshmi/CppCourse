//
// Created by Lakshmi S Patel on 30/05/21.
//

#ifndef CPPCOURSE_ADJMATGRAPH_H
#define CPPCOURSE_ADJMATGRAPH_H
#include <iostream>
#include <vector>
using namespace std;

class AdjMatGraph{
public:
    int v;
    vector<vector<int>> adjMat;
    AdjMatGraph(int v){
        this->v = v;
        vector<vector<int>> adjMat(v, vector<int>(v));
        this->adjMat = adjMat;
    }

    void add(int u, int v, int weight){
        adjMat[u][v] = weight;
    }

    int getWeight(int u, int v){ return adjMat[u][v]; }

    void print(){
        for(vector<int> v: this->adjMat){
            for(int x: v){ cout<< " "<< x; }
            cout<< endl;
        }
    }

};

#endif //CPPCOURSE_ADJMATGRAPH_H
