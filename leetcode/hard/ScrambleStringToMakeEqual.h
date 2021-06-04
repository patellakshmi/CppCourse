//
// Created by Lakshmi S Patel on 23/05/21.
//

#ifndef CPPCOURSE_SCRAMBLESTRINGTOMAKEEQUAL_H
#define CPPCOURSE_SCRAMBLESTRINGTOMAKEEQUAL_H
#include <map>
#include <string>

using namespace std;

/*
 *
 *
   Scramble String
   ===============
    We can scramble a string s to get a string t using the following algorithm:

    If the length of the string is 1, stop.
    If the length of the string is > 1, do the following:
    Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
    Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
    Apply step 1 recursively on each of the two substrings x and y.
    Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

 *
 *
 */


/*
 * Explanation:
 * let we have two string s1, s2
 * there is two possibility:
 * divide the two string at ith index
 * s1 = x + y
 * s2 = s + t
 *
 * if x,t and s,y make our solution by recursion approach than yes scramble is possible
 * if x,s and y,t make our solution possible by recursive approach that yes scramble is possible
 *
 * let at sub-problem we got solution for so it better to store that solution in somewhere so that in future
 * if similar kind of problem come, we immediately get the result.
 *
 *
 *
 *
 */



class Scramble {
public:
    unordered_map<string, bool> mp;
    bool solve(string s1, string s2) {

        if(s1 == s2)
            return true;

        if(s1.length() != s2.length())
            return false;

        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end())
            return mp[key];

        bool result = false;
        int n = s1.length();
        for(int i = 1; i<n; i++) {
            /*
            Example : "great"  "eatgr"
            if swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(n-i, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(0, n-i) i.e. "eat"
            */

            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i)) &&
                           solve(s1.substr(i, n-i), s2.substr(0, n-i));
            if(swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }
            /*
            Example : "great"  "great"
            if not swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(0, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(i, n-i) i.e. "eat"
            */

            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
                               solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(not_swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }

        }

        return mp[key] = result;
    }
    bool isScramble(string &s1, string &s2) {
        mp.clear();
        return solve(s1, s2);
    }
};


#endif //CPPCOURSE_SCRAMBLESTRINGTOMAKEEQUAL_H
