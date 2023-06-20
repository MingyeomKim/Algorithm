#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Element{
public: 
    int priority; 
    int order; 
    
    Element(int priority, int order) : priority(priority), order(order) {}
};

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int> pq; 
    queue<Element> q;
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]); // 9 1 1 1 1 1
        q.push(Element(priorities[i], i)); // 1 1 9 1 1 1 
    }
    while(!q.empty()){
        Element e = q.front(); 
        if(e.priority == pq.top()){
            pq.pop(); q.pop(); 
            answer++; 
            if(e.order == location)
                return answer;
        } else{
            q.pop(); q.push(e); 
        }
    }    
    return answer;
}