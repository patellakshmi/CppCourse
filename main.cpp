#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/*
class node{
public:
    node* left; //0
    node right; //1
    vector v;
};
class trie{
public:
    noderoot;
    trie(){
        root = new node();
    }
    void insert(int n){
        nodetemp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0)
            {
                if(temp->left)
                {
                    temp=temp->left;
                }
                else
                {
                    temp->left= new node();
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->right)
                {
                    temp=temp->right;
                }
                else
                {
                    temp->right=new node();
                    temp=temp->right;
                }
            }
            temp->v.push_back(n);
        }
    }
    int search(int n, int lt)
    {
        long long int ans=0;
        nodetemp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
// cout<<bit;
            if(bit==0)
            {
                if(temp->right and temp->right->v[0]<=lt)
                {
                    temp=temp->right;
                    ans+=pow(2,i);
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->left and temp->left->v[0]<=lt)
                {
                    temp=temp->left;
                    ans+=pow(2,i);
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector maximizeXor(vector& n, vector<vector>& q) {
        sort(n.begin(),n.end());
        trie t;
        for(auto x:n)
        {
            t.insert(x);
        }
        vectorans(q.size());
        for(int i=0;i<q.size();i++)
        {
            if(q[i][1]<n[0])
            {
                ans[i]=-1;
            }
            else if(q[i][1]==n[0])
            {
//cout<<q[i][1]<<endl;
                ans[i]=n[0]^q[i][0];
            }
            else
            {
                ans[i]=t.search(q[i][0],q[i][1]);
            }
//cout<<ans[i]<<endl;
        }
        return ans;
    }
};


int main()
{
   vector<vector<int>> v{{{0,1,-1},{1,0,-1},{1,1,1}}};
   Solution s;
   cout<< "\n Exp value is: "<< s.cherryPickup(v);
   return 0;
}

 */