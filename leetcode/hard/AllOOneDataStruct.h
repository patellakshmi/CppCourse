/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 27/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_ALLOONEDATASTRUCT_H
#define CPPCOURSE_ALLOONEDATASTRUCT_H

#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std;

class AllOne {
    map<string,int> ms;
    set<string> s;

    std::string ZeroPadNumber(int num) {
        std::ostringstream ss;
        ss << std::setw(4) << std::setfill('0') << num;
        return ss.str();
    }
public:

    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(ms.find(key) == ms.end()){
            ms[key]++;
            string keyValue = ZeroPadNumber(1)+"#"+key;
            s.insert(keyValue);
        }else{
            int count = ms[key];
            string oldKeyValue = ZeroPadNumber(count)+"#"+key;
            s.erase(oldKeyValue);
            ms[key]++;
            string newKeyValue = ZeroPadNumber(count+1)+"#"+key;
            s.insert(newKeyValue);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(ms.find(key) == ms.end()){

        }else{
            int count = ms[key];
            string oldKeyValue = ZeroPadNumber(count)+"#"+key;
            s.erase(oldKeyValue);
            if( count > 1){
                string newKeyValue = ZeroPadNumber(count-1)+"#"+key;
                s.insert(newKeyValue);
            }
            ms[key]--;
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if( s.empty() ) return "";
        set<string>::iterator it = s.end();
        it--;
        string maxString = *it;
        int i = maxString.find('#');
        return maxString.substr(i+1);
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if( s.empty() ) return "";
        set<string>::iterator it = s.begin();
        string maxString = *it;
        int i = maxString.find('#');
        return maxString.substr(i+1);
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

#endif //CPPCOURSE_ALLOONEDATASTRUCT_H
