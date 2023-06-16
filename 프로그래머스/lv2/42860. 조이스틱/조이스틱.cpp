#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minCount(char target){
    return min(target - 'A', 'Z' - target + 1);
}

int solution(string name) {
    int answer = 0;
    
    int n= name.length();
    int turn = n - 1; 
    for(int i= 0; i< n; i++) {
        answer += minCount(name[i]);
        
        int ind = i + 1;
        while(ind < n && name[ind] == 'A') ind++;
        
        turn = min(turn, i + n - ind + min(i, n - ind)); 
    }
    answer += turn; 
    return answer;
}