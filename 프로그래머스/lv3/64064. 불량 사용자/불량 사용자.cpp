#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

bool isCombined(string s, string id){
    if(s.length() != id.length()) return false; 
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '*') continue; 
        if(s[i] != id[i]) return false; 
    }
    return true; 
}

void recursive(int index, vector<vector<int>> candidates, set<int> & selected, set<set<int>> & s){
    if(index == candidates.size()) {
        s.insert(selected); 
        return ;
    }
    for(int x : candidates[index]){
        if(selected.find(x) != selected.end()) continue; 
        selected.insert(x);
        recursive(index + 1, candidates, selected, s); 
        selected.erase(x); 
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int n = banned_id.size(), m = user_id.size(); 
    vector<vector<int>> candidates(n); 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(isCombined(banned_id[i], user_id[j]))
                candidates[i].push_back(j); 
    }
    
    set<int> selected;
    set<set<int>> s; 
    recursive(0, candidates, selected, s); 
    
    return s.size();
}