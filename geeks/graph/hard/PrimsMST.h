//
// Created by Lakshmi S Patel on 30/05/21.
//

#ifndef CPPCOURSE_PRIMSMST_H
#define CPPCOURSE_PRIMSMST_H
#include <iostream>
#include <deque>
#include <queue>

#include "../AdjMatGraph.h";
#include "../DisjointSets.h";
using namespace std;

class PrimsMST{
public:
    AdjMatGraph adjMatGraph;
    vector<bool> mstSet;
    vector<int> keys;
    vector<int> parent;
    PrimsMST(AdjMatGraph adjMatGraph){
        this->adjMatGraph = adjMatGraph;
        vector<int> mstSet(adjMatGraph.v,false);
        this->mstSet =mstSet;
        vector<int> parent(adjMatGraph.v,-1);
        this->parent = parent;
        vector<int> key(adjMatGraph.v,INT_MAX);
        this->keys = key;
    }

    int minKey(vector<int> key, vector<int> mstSet){
        int min = INT_MAX, minIndex;
        for(int v = 0; v < adjMatGraph.v; v++){
            if( mstSet[v] == false && key[v] < min){
                min = key[v], minIndex = v;
            }
        }

        return minIndex;
    }

    vector<vector<int>> minSpanningTree(){
            key[0] = 0;
            parent[0] = -1;
            for(int i = 0; i < adjMatGraph.v; i++){
                int u = minKey(key, mstSet);
                mstSet[u] = true;
                for(int v = 0; v < adjMatGraph.v; v++){
                    if( adjMatGraph[u][v] < key[v] && mstSet[v] == false && adjMatGraph[u][v]){
                        parent[v] = u, key[v] = adjMatGraph[u][v];
                    }
                }
            }

        vector<vector<int>> spanMat(disjointSets.parent.size(), vector<int>(disjointSets.parent.size()));
        for(int i = 0; i < parent.size(); i++){
            int pI = parent[i];
            spanMat[pI][u] = adjMatGraph[pi][u];
        }

        return spanMat;
    }


    vector<vector<int>> minSpanningTreeSTL(){
        key[0] = 0;
        parent[0] = -1;
        priority_queue<pair<int, int >, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int src = 0;
        pq.push({0, src});

        while (!pq.empty()){
            pair<int,int> t = pq.top();
            int weight = t.first;
            int u = t.second;
            pq.pop();
            for(int i = 0; i < adjMatGraph.v; i++){
                if (inMST[v] == false && adjMatGraph[u][i] >  weight){
                    key[i] = adjMatGraph[u][i]+weight;
                    pq.push(make_pair(key[i], v));
                    parent[v] = u;
                }
            }
        }

        vector<vector<int>> spanMat(disjointSets.parent.size(), vector<int>(disjointSets.parent.size()));
        for(int i = 0; i < parent.size(); i++){
            int pI = parent[i];
            spanMat[pI][u] = adjMatGraph[pi][u];
        }

        return spanMat;
    }


};

#endif //CPPCOURSE_PRIMSMST_H
