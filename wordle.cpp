// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <unordered_map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void solveWordle(string s, const string& in, string floating, const set<string>& dict, set<string>& ret){
    int n = s.size();
    if (n==in.size()){
        
        if (!floating.empty() || dict.find(s) == dict.end()) return;
        ret.insert(s);
        return;
    }
    if (in[n]!='-'){
        solveWordle(s+in[n], in, floating, dict, ret);
        return;
    }
    for (char c = 'a'; c<= 'z'; c++ ){
        auto x = floating.find(c);
        if (x!=string::npos){
            string temp = floating;
            floating.erase(x,1);
            solveWordle(s+c, in, floating, dict, ret);
            floating = temp;
            continue;
        }
        solveWordle(s+c, in, floating, dict, ret);
    }
    return;

}
// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    
    set<string> ret;

    solveWordle("", in, floating, dict, ret);
    return ret;

}

// Define any helper functions here
