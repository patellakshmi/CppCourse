//
// Created by Lakshmi S Patel on 31/05/21.
//

#ifndef CPPCOURSE_TOPOLOGICALSHORT_H
#define CPPCOURSE_TOPOLOGICALSHORT_H
#include <iostream>
#include "../AdjMatGraph.h";
#include "../DisjointSets.h";
#include <stack>
using namespace std;

class TopologicalShort{
    AdjMatGraph adjMatGraph;
public:
    TopologicalShort(AdjMatGraph adjMatGraph){ this->adjMatGraph = adjMatGraph;}

    void topologicalShortUtil(int vertex, vector<int> visited, stack<int> &st){
        visited[vertex] = true;
        st.push(vertex);
        for(int i = 0; i < adjMatGraph.v; i++){
            if( !visited[i] && adjMatGraph[v][i] ){
                topologicalShortUtil(i, visited, st);
            }
        }
    }


    void Graph::allTopologicalSortUtil(vector<int>& res,
                                       bool visited[]){
        bool flag = false;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0 && !visited[i])
            {
                list<int>:: iterator j;
                for (j = adj[i].begin(); j != adj[i].end(); j++) indegree[*j]--;

                res.push_back(i);
                visited[i] = true;
                alltopologicalSortUtil(res, visited);

                visited[i] = false;
                res.erase(res.end() - 1);
                for (j = adj[i].begin(); j != adj[i].end(); j++)
                    indegree[*j]++;

                flag = true;
            }
        }

        if (!flag)
        {
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << " ";
            cout << endl;
        }
    }

    vector<int> topologicalShort(){
        vector<bool> visited(adjMatGraph.v);
        memset(visited, false, sizeof(visited));
        stack<int> st;
        topologicalShortUtil(0, visited, st);
        vector<int> res;
        while (!st.empty()){ res.push_back(st.top()); st.pop(); }
        return res;
    }


};


#endif //CPPCOURSE_TOPOLOGICALSHORT_H
