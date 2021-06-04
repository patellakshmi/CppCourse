//
// Created by Lakshmi S Patel on 30/05/21.
//

#ifndef CPPCOURSE_DISJOINTSETS_H
#define CPPCOURSE_DISJOINTSETS_H

class DisjointSets{
public:
    vector<int> parent;
    DisjointSets(int n){
        vector<int> parent(n);
        this->parent = parent;
        for(int i = 0; i < n; i++){
            parent[i] = -1;
        }
    }

    int find(int u){
        while( parent[u] >= 0 )  u = parent[u];
        return parent[u];
    }

    int merge(int x, int y){
        int pX = find(x);
        int pY = find(y);
        if( pX < pY ){
            parent[pY] = pX;
            parent[pX] = pX+pY;
        }else{
            parent[pX] = pY;
            parent[pY] = pX+pY;
        }
    }

};

#endif //CPPCOURSE_DISJOINTSETS_H
