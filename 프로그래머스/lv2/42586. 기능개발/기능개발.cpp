#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q; 
    for(int x : progresses)
        q.push(x); 
    while(!q.empty()){
        int n = progresses.size(); 
        for(int i = 0; i < n; i++)
            progresses[i] += speeds[i]; 
        
        int cnt = 0;  // 한 번에 배포한 작업의 수
        while(progresses[0] >= 100){
            cnt++; 
            q.pop(); 
            progresses.erase(progresses.begin()); // 처음 숫자 없애기
            speeds.erase(speeds.begin()); 
            if(progresses.empty()) break;
        }
        if(cnt != 0)
            answer.push_back(cnt); 
    }
    
    return answer;
}

/*

93 30 55
94 60 60 
95 90 65
96 120 70
97 150 75
98 180 80
99 210 85
100 240 90

*/