//
// Created by Lakshmi S Patel on 02/06/21.
//

#ifndef CPPCOURSE_MAXFLOWFORDFULKERSON_H
#define CPPCOURSE_MAXFLOWFORDFULKERSON_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "../medium/AdjMatGraph.h"

using namespace std;

class MaxFlowFordFulkerson{
private:
    AdjMatGraph adjMatGraph;
    AdjMatGraph resGraph;
    vector<int> parent;

public:

    MaxFlowFordFulkerson(AdjMatGraph adjMatGraph){
        this->adjMatGraph = adjMatGraph;
        for(int i = 0; i < adjMatGraph.v; i++)
            for(int j = 0; j < adjMatGraph.v; j++){
                resGraph[i][j] = adjMatGraph[i][j];
            }

        vector<int> p(adjMatGraph.v);
        this->parent = p;
        for(int i = 0; i < adjMatGraph.v; i++){
            this->parent[i] = -1;
        }
    }

    bool getPathUsingBSF(int source, t dest);

    int fordFulkerson(int s, int t){

        int max_flow = 0;
        int u, v;
        memset(parent,-1, sizeof(parent));
        while (bfs(rGraph, s, t, parent)) {
            int path_flow = INT_MAX;
            for (v = t; v != s; v = parent[v]) {
                u = parent[v];
                path_flow = min(path_flow, rGraph[u][v]);
            }

            for (v = t; v != s; v = parent[v]) {
                u = parent[v];
                rGraph[u][v] -= path_flow;
                rGraph[v][u] += path_flow;
            }

            max_flow += path_flow;
        }

        return max_flow;
    }
}


};

bool MaxFlowFordFulkerson::getPathUsingBSF(int source, t dest){

    queue<int> q;
    q.push(source);
    parent[source] = -1;
    vector<bool> visited(adjMatGraph.v);
    memset(visited, false, sizeof(v));

    while (!q.empty()){
        int node = q.front(); q.pop();
        for(int i = 0; i < adjMatGraph.v && i != node ; i++){
            if( adjMatGraph[node][i] > 0 && visited[i] == false ){
                q.push(i);
                parent[i] = node;
                visited[i] = true;
            }
        }
    }

    return (visited[t] == true);
}

#endif //CPPCOURSE_MAXFLOWFORDFULKERSON_H
