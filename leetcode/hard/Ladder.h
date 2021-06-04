//
// Created by Lakshmi S Patel on 26/05/21.
//

#ifndef CPPCOURSE_LADDER_H
#define CPPCOURSE_LADDER_H

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    string word="";
    list<Node *> l;
    vector<string> vString;

    Node(string word){
        this->word = word;

    }
};

class Solution {
public:

    int min(int a, int b) { return a > b ? b: a; }

    bool isNotPreset(vector<string> l,string word){
        bool isFound = false;
        for(string str: l){
            if( word == str){
                isFound = true;
            }
        }

        return !isFound;
    }
    int wordDiff(string word1, string word2){
        int count = 0;
        for(int i = 0; i < word1.size(); i++){
            count += ( word1[i] == word2[i]) ? 0 : 1;
        }
        return count;
    }

    void formStringVector(Node *root, vector<vector<string>> &res, string &endWord){

        if( root->word == endWord){
            res.push_back(root->vString);
            return;
        }

        if( root->l.size() == 0) return;

        list<Node *> l = root->l;
        for(Node *node : l){
            formStringVector(node, res, endWord);
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {

        deque<Node*> d;
        Node *root = new Node(beginWord);
        root->vString.push_back(beginWord);
        d.push_back(root);

        Node *temp;
        while(!d.empty()){
            temp = d.front(); d.pop_front();
            for(string word: wordList){
                if( isNotPreset(temp->vString, word) && 1 == wordDiff(temp->word, word)) {
                    Node *newNode = new Node(word);
                    vector<string> tempV(temp->vString);
                    tempV.push_back(word);
                    newNode->vString = (tempV);
                    temp->l.push_back(newNode);
                    d.push_back(newNode);
                }
            }
        }

        vector<vector<string>> res;
        formStringVector(root, res, endWord);

        if( res.size() == 0) {
            vector<vector<string>> zeroV;
            return zeroV;
        }

        int minSize = res[0].size();
        for(vector<string> v: res){
            minSize = min(minSize, v.size());
        }

        vector<vector<string>> fres;
        for(vector<string> v: res){
            if( v.size() == minSize){
                fres.push_back(v);
            }
        }

        return fres;
    }
};


#endif //CPPCOURSE_LADDER_H
