#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int find(vector<pair<string, int>> cache, string s){
    for(int i =0; i < cache.size(); i++){
        if(cache[i].first == s) return i; 
    }
    return -1; 
}

int findTarget(vector<pair<string,int>> cache){
    int min = 100001; 
    int min_index = 0; 
    for(int i = 0;i < cache.size(); i++){
        if(cache[i].second < min) {
            min = cache[i].second; 
            min_index = i; 
        }
    }
    return min_index; 
}

int solution(int cacheSize, vector<string> cities) {
    vector<pair<string, int>> cache; // 객체, 가장 최근에 사용된 시간
    
    int answer = 0;
    for(int i = 0; i < cities.size(); i++){
        for(char &c : cities[i]){
            if(islower(c))
                c = toupper(c); 
        }
        int idx = find(cache, cities[i]); 
        if(idx != -1){
            answer++; 
            cache[idx].second = i; // LRU 갱신
        } else {
            answer += 5; 
            if(cache.size() < cacheSize)
                cache.emplace_back(cities[i], i); 
            else {
                if(cacheSize == 0) continue;
                int target = findTarget(cache); 
                cache[target] = make_pair(cities[i], i); 
            }
        }
    }
    return answer;
}
