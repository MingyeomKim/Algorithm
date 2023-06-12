#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

bool isAlpha(char c){
    return c >= 'a' && c <= 'z'; 
}

int solution(string str1, string str2) {
    int answer = 0;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower); 
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower); 

    vector<string> v1, v2; 
    for(int i = 0; i < str1.length(); i++){
        string s = str1.substr(i, 2); 
        if(isAlpha(s[0]) && isAlpha(s[1])) v1.push_back(s); 
    }
     for(int i = 0; i < str2.length(); i++){
        string s = str2.substr(i, 2); 
        if(isAlpha(s[0]) && isAlpha(s[1])) v2.push_back(s); 
    }
    
    if(v1.empty() && v2.empty()) return 65536;
    
    int max = v1.size() + v2.size(); 
    int min = 0; 
    for(int i = 0; i < v1.size(); i++){
        auto iter = find(v2.begin(), v2.end(), v1[i]); 
        if(iter != v2.end()){
            min++; 
            v2.erase(iter); 
        }
    }
    max -= min; 
    
    if(max == 0) return 65536;
    else return min * 65536 / max;
}