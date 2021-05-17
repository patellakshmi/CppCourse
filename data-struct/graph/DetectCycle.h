//
// Created by Lakshmi S Patel on 18/05/21.
//

#ifndef CPPCOURSE_DETECTCYCLE_H
#define CPPCOURSE_DETECTCYCLE_H

#include "Graph.h"
#include <iostream>
#include <queue>
#include <set>
using namespace std;

class DetectCycle{

    bool isCycleDetectedUtilDFS(int v, bool *visited, int parent, Graph graph){
        visited[v] = true;
        for(auto i: graph.getAdjList(v)){
            if( !visited[i] && isCycleDetectedUtilDFS(i, visited, parent, graph)){
                return true;
            }else if( i != parent ){
                return true;
            }
        }
        return false;
    }

    bool isCycleDetectedUtilBFS(int v, bool *visited, Graph graph){

        vector<int> parent(graph.getTotalVertex(), -1);

        queue<int> q;
        visited[v] = true;
        q.push(v);

        while ( !q.empty()){
            int u = q.front();
            q.pop();
            for( auto v: graph.getAdjList(u)){
                if( !visited[v]){
                    visited[v] = true;
                    q.push(v);
                    parent[v] = u;
                }else if( parent[u] != u ){
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycleDetectedDFS(Graph graph){

        bool *visited = new bool[graph.getTotalVertex()];
        for(int i = 0; i < graph.getTotalVertex(); i++){
            visited[i] = false;
        }

        for(int u = 0; u < graph.getTotalVertex(); u++){
            if( !visited[u]){
                if( isCycleDetectedUtilDFS(u, visited, -1, graph)){
                    return true;
                }
            }
        }

        return false;

    }

    bool isCycleDetectedBFS(Graph graph){

        bool *visited = new bool[graph.getTotalVertex()];
        for(int i = 0; i < graph.getTotalVertex(); i++){
            visited[i] = false;

        }

        for(int u = 0; u < graph.getTotalVertex(); u++){
            if( !visited[u]){
                if( isCycleDetectedUtilBFS(u, visited, graph )){
                    return true;
                }
            }
        }

        return false;

    }

};

#endif //CPPCOURSE_DETECTCYCLE_H
