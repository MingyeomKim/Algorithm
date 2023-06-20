#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

long long calc(long long a, long long b, char c){
    if(c == '+') return a + b; 
    else if (c == '-') return a - b; 
    else return a * b; 
}

long long recursive(vector<long long> n, string s, string priorities){
    long long result = 0; 
    
    for(char c : priorities){ // 연산자 우선순위 순서대로 계산
        int j = 0; // 연산자(s)의 인덱스
        vector<long long> nn; 
        string ss;
        nn.push_back(n[0]);
        
        while(true){
            if(j == s.length()) break;
            
            if(s[j] == c) {  
                long long last = nn.back(); nn.pop_back(); 
                nn.push_back(calc(last, n[j + 1], s[j]));
                j++;
            } else {
                nn.push_back(n[j + 1]); 
                ss.push_back(s[j]); 
                j++; 
            }
        }
        result = nn.back(); 
        
        n = nn; 
        s = ss;
    }
    return result; 
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> n; string s; 
    string number;

    string priorities;
    for(char c : expression){
        if(c == '+' || c == '-' || c =='*') {
            s += c;
            if(priorities.find(c) == string::npos) // 최초로 발견된 부호라면
                priorities.push_back(c); 
            n.push_back(stoi(number)); 
            number.clear(); 
        }
        else 
            number += c; 
    }
    n.push_back(stoi(number)); 

    sort(priorities.begin(), priorities.end()); 
    do{
        long long cand = recursive(n, s, priorities); 
        if(answer < abs(cand)) answer = abs(cand); 
    } while(next_permutation(priorities.begin(), priorities.end()));

    return answer;
}