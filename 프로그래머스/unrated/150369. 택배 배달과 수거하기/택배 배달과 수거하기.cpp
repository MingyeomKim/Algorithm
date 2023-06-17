#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    while(true) {
        if(deliveries.size() == 0 && pickups.size() == 0) break;
        
        while(deliveries.size() > 0 && deliveries.back() == 0)
            deliveries.pop_back();
        while(pickups.size() > 0 && pickups.back() == 0)
            pickups.pop_back();
        
        int i = deliveries.size() - 1, j = pickups.size() - 1;
        
        int sum = 0; 
        for(int x : deliveries){
            sum += x;
            if(sum >= cap) {
                sum = cap; 
                break;
            }
        }
        
        int cnt = 0;
        while(deliveries.size() > 0){
            if(deliveries[i] > 0){
                deliveries[i]--;
                cnt++;
            } else if(deliveries[i] == 0){
                if(i > 0) i--;
                else break;
            }
            if(cnt == sum) break;
        }
        
        cnt = 0; 
        while(pickups.size() > 0){
            if(pickups[j] > 0){
                pickups[j]--; 
                cnt++; 
            } else if (pickups[j] == 0){
                if(j > 0) j--; 
                else break;
            }
            if(cnt == cap) break;
        }
        
        answer += (max(deliveries.size(), pickups.size()) * 2);
        
        // deliveries와 pickups의 뒤쪽에 있는 0을 차례로 제거한다. 
        while(deliveries.size() > 0 && deliveries.back() == 0)
            deliveries.pop_back();
        while(pickups.size() > 0 && pickups.back() == 0)
            pickups.pop_back();
    }
    
    return answer;
}