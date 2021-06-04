//
// Created by Lakshmi S Patel on 26/05/21.
//

#ifndef CPPCOURSE_TRIE_H
#define CPPCOURSE_TRIE_H


#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <thread>
#include <list>
#include <stack>

using namespace std;

class TrieNode{
public:
    bool isWordEndHere = { false};
    char ch;
    TrieNode *alphaArr[26]={};


    TrieNode(){

    }

    TrieNode(char ch){
        this->ch = ch;
    }

    TrieNode(char ch,bool isWordEndHere){
        this->ch = ch;
        this->isWordEndHere = isWordEndHere;
    }
    void setEndWordHere(){
        this->isWordEndHere = true;
    }
    void setNewTrieNode(TrieNode *newNode){
        if( newNode->ch >= 'a' && newNode->ch <= 'z'){
            this->alphaArr[newNode->ch-'a'] = newNode;
        }
    }

    TrieNode *getTrieNode(char a){
        return this->alphaArr[a-'a'];
    }

};

class Solution {
public:

    TrieNode * createTrie(vector<string> &v){
        TrieNode *root = new TrieNode('$');

        for(string str: v){
            TrieNode *node = root;
            for(int i = 0; i < str.size(); i++){
                TrieNode *temp = node->alphaArr[str[i]-'a'];
                if( temp == nullptr) {
                    temp = new TrieNode(str[i]);
                    node->setNewTrieNode(temp);
                    if( i == (str.size()-1)) temp->setEndWordHere();
                }else{
                    if( i == (str.size()-1)) temp->setEndWordHere();
                }

                node = temp;
            }
        }

        return root;
    }

    bool isPresent(TrieNode *root, string str){

        TrieNode *node = root;
        for(int i = 0; i < str.size()-1; i++){
            if( node->ch == str[i]){
                node = node->alphaArr[str[i+1]-'a'];
                if( node == nullptr) return false;
            }else{
                return false;
            }
        }

        if(node->ch == str[str.size()-1] && node->isWordEndHere == true) return true;
        return false;

    }

};



#endif //CPPCOURSE_TRIE_H
