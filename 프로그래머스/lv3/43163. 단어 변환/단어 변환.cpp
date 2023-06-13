#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dist[51]; 

bool isOnce(string a, string b){
    int cnt = 0; 
    for(int i =0; i < a.length(); i++){
        if(a[i] != b[i]) cnt++; 
        if(cnt > 1) return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    memset(dist, -1, sizeof(dist)); 
    
    if(find(words.begin(), words.end(), target) == words.end())
        return 0; 
    
    vector<string> tmp; 
    tmp.push_back(begin); 
    for(string s : words)
        tmp.push_back(s);
    words = tmp; 
    
    vector<vector<int>> graph(words.size(), vector<int>(words.size()));
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words.size(); j ++){
            if(i == j) continue; 
            if(isOnce(words[i], words[j])) // 한 개만 겹치는 경우
                graph[i].push_back(j); 
        }
    }
    
    queue<int> q; 
    q.push(0); 
    dist[0] = 0; 
    while(!q.empty()){
        int n = q.front(); q.pop(); 
        for(int i = 0; i < graph[n].size(); i++){
            int nn = graph[n][i];
            if(dist[nn] != -1) continue;
            q.push(nn); 
            dist[nn] = dist[n] + 1;
        }
    }
    
    int find_target; 
    for(int i = 0; i< words.size(); i++)
        if(words[i] == target){
            find_target = i; 
            break;
        }
    if(dist[find_target] == -1) return 0; 
    else return dist[find_target]; 
}