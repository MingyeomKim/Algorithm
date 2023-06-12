#include <string>
#include <vector>
#include <iostream>

using namespace std;

string digit_to_binary(int n){
    string ret = ""; 
    while(n != 0){
        char c = (n % 2 == 0) ? '0' : '1'; 
        ret.push_back(c); 
        n /= 2; 
    }
    return ret; 
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0, sum = 0; 
    while(true) {
        if(s.length() < 2) break;
        cnt++; 
        
        string tmp = ""; 
        for(int i =0; i< s.length(); i++){
            if(s[i] == '1') tmp.push_back(s[i]); 
            else sum++;
        }
        int c = tmp.length();
        tmp = digit_to_binary(c);
        s = tmp; 
    }
    answer.push_back(cnt); 
    answer.push_back(sum); 
    return answer;
}