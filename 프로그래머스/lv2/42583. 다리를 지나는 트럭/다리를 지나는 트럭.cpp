#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // 시간
    
    queue<int> q; 
    int sum = 0; // 현재 다리에 있는 트럭의 총 무게 
    int i = 0; 
    while(true) { 
        if(i == truck_weights.size()){
            answer += bridge_length; 
            break;
        }
        answer++; 
        if(q.size() == bridge_length){
            sum -= q.front(); 
            q.pop(); 
        }
        
        int w = truck_weights[i]; 
        if(sum + w > weight)
            q.push(0); 
        else {
            q.push(w); 
            sum += w;
            i++; 
        }
    }
    return answer;
}