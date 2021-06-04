//
// Created by Lakshmi S Patel on 26/05/21.
//

#ifndef CPPCOURSE_TRIEDS_H
#define CPPCOURSE_TRIEDS_H
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

class Trie{
public:
    char ch = {'#'};
    bool isWordEnd={false};
    Trie *child[26]={};
    Trie(){}
    Trie(char ch) { this->ch = ch; }
    Trie(char ch, bool isWordEnd){ this->ch = ch, this->isWordEnd = isWordEnd;}
    char getChar(){ return this->ch; }
    void setChar(char ch){ this->ch = ch;}
    bool isWordEndChar(){ return this->isWordEnd; }
    void setWordEndChar(bool isWordEnd){ this->isWordEnd = isWordEnd;}
    void setChild(Trie *node){
        if( node->ch >= 'a' && node->ch <= 'z'){
            this->child[node->ch-'a'] = node;
        }
    }
    Trie* getChild(char ch){
        if( ch >= 'a' && ch <= 'z'){
            return this->child[ch-'a'];
        }
        throw "Invalid Char";
    }
};

class TrieDS{

public:
    Trie *root={};

    void create(vector<string> v){

        Trie *root = new Trie('$');

        for(string str: v){
            Trie *node = root;
            for(int i = 0; i < str.size(); i++){
                Trie *existNode = node->child[str[i]-'a'];
                if( existNode == nullptr ) {
                    existNode = new Trie(str[i]);
                    node->setChild(existNode);
                }
                if( i == str.size()-1){
                    existNode->setWordEndChar(true);
                }

                node = existNode;
            }
        }
        this->root = root;
    }

    void add(vector<string> v){
        Trie *root = this->root;
        if( root == nullptr )
            root = new Trie('$');

        for(string str: v){
            Trie *node = root;
            for(int i = 0; i < str.size(); i++){
                Trie *existNode = node->child[str[i]-'a'];
                if( existNode == nullptr ) {
                    existNode = new Trie(str[i]);
                    node->setChild(existNode);
                }
                if( i == str.size()-1){
                    existNode->setWordEndChar(true);
                }

                node = existNode;
            }
        }

    }

    void add(string str){
        Trie *root = this->root;
        if( root == nullptr )
            root = new Trie('$');


        Trie *node = root;
        for(int i = 0; i < str.size(); i++){
            Trie *existNode = node->child[str[i]-'a'];
            if( existNode == nullptr ) {
                existNode = new Trie(str[i]);
                node->setChild(existNode);
            }
            if( i == str.size()-1){
                existNode->setWordEndChar(true);
            }

            node = existNode;
        }

    }

    bool isPresent(string word){
        if( this->root == nullptr ) throw "Create TrieDS first using create:function";
        Trie *node = this->root;
        for(int i = 0; i < word.size()-1; i++){
            if( node->ch != word[i]) return false;
            node = node->getChild(word[i+1]);
        }

        if( word[word.size()-1] == node->ch && node->isWordEnd == true) return true;
        return false;

    }


};

#endif //CPPCOURSE_TRIEDS_H
