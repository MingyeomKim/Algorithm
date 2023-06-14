#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>, greater<int>> pq; // 최소 힙
    
    for(int x : scoville)
        pq.push(x); 
    while (pq.size() > 1 && pq.top() < K){
        answer++;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
    }
    if(!pq.empty() && pq.top() >= K) return answer;
    else return -1;
}