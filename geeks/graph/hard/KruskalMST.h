//
// Created by Lakshmi S Patel on 30/05/21.
//

#ifndef CPPCOURSE_KRUSKALMST_H
#define CPPCOURSE_KRUSKALMST_H

#include <iostream>
#include "../AdjMatGraph.h";
#include "../DisjointSets.h";
using namespace std;

class KruskalMST{
public:
    AdjMatGraph adjMatGraph;
    DisjointSets disjointSets;
    vector<int, vector<int,int>> edges;

    KruskalMST(AdjMatGraph adjMatGraph, DisjointSets disjointSets){
        this->adjMatGraph = adjMatGraph;
        this->disjointSets = disjointSets;
    }

    vector<vector<int>> minSpanningTree(){

        for(int i = 0; i < adjMatGraph.v; i++){
            for(int j = 0; j < adjMatGraph.v; j++){
                if( i != j){
                    edges.push_back({ adjMatGraph.getWeight(i, j), {i, j }});
                }
            }
        }

        sort(edges, edges+adjMatGraph.v);
        vector<int, vector<int,int>>::iterator it;
        for(it = edges.begin(); it != edges.end(); it++){
            int u = it->second.first;
            int v = it->second.second;
            int set_u = disjointSets.find(u);
            int set_v = disjointSets.find(v);
            if( set_u != set_v){
                disjointSets.merge(set_u, set_v);
            }
        }

        vector<vector<int>> spanMat(disjointSets.parent.size(), vector<int>(disjointSets.parent.size()));
        vector<int> parent = disjointSets.parent;
        for(int i = 0; i < parent.size(); i++){
            int pI = parent[i];
            spanMat[pI][u] = adjMatGraph[pi][u];
        }

        return spanMat;

    }


};

#endif //CPPCOURSE_KRUSKALMST_H
