#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <iostream>

using namespace std;

// 균형잡힌 문자열 u, v로 변환
pair<string,string> distribute(string w){
    int open = 0, close = 0; 

    int i; 
    for(i = 0; i < w.length() - 1; i++){
        if(w[i] == '(') open++; 
        else close++; 
        if(open == close) break;
    }
    return make_pair(w.substr(0, i + 1), w.substr(i + 1)); 
}

// 올바른 괄호 문자열인지 확인
bool check(string w){
    stack<char> st; 
    for(char c : w){
        if(c == '(') st.push(c); 
        else {
            if(st.empty())
                return false; 
            else
                st.pop(); 
        }
    }
    return true; 
}

void reverse(string &s){ 
    for(int i =0; i < s.length(); i++)
        if(s[i] == '(') s[i] = ')'; 
        else s[i] = '('; 
}

string change(string w){
    if(w.empty()) return ""; 
    if(check(w)) return w; 
    
    auto p = distribute(w); 
    string u = p.first, v = p.second; 
    cout << "u : " << u << ", v : " << v << endl;
    if(check(u)){
        cout << "check(u)" << endl;
        return u + change(v); 
    } else {
        cout << "!check(u)" << endl;
        string s = "(" + change(v) + ")"; 
        u = u.substr(1);  u.pop_back(); 
        reverse(u); 
        return s + u; 
    }
}

string solution(string p) {
    string answer = "";
    answer = change(p); 
    return answer;
}

/*
1. 균형잡힌 문자열로 분리하는 과정
2. 올바른 괄호 문자열인지 확인하는 과정

예외처리 : v가 균형잡힌 문자열이 아닌 경우, change에 들어가서 올바른 답을 내지 못한다.
*/