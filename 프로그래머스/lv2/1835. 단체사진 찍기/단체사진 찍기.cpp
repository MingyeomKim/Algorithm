#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

vector<tuple<char,char,int>> info['Z' + 1];

void preprocess(vector<string> data){
    for(string s : data){
        info[s[0]].emplace_back(s[2], s[3], s[4] - '0'); 
        info[s[2]].emplace_back(s[0], s[3], s[4] - '0'); 
    }
}

// 조건에 맞는 지 확인
bool check(int index, string people){
    bool flag = true;
    char c = people[index]; 
    for(auto t : info[c]){
        char target, sign; int dist; 
        tie(target, sign, dist) = t;
        
        int k = 0; 
        for(int i = 0; i < people.length(); i++){
            if(people[i] == target){
                k = i;
                break;
            }
        }
        int n = abs(k - index) - 1; 
        if(sign == '=')
            flag = (n == dist); 
        else if(sign == '>')
            flag = (n > dist); 
        else if(sign == '<')
            flag = (n < dist); 
        if(!flag) return flag;
    }
    return flag;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    for(int i = 'A'; i <= 'Z'; i++)
        info[i].clear();
    int answer = 0;
    preprocess(data); 
    string people = "ACFJMNRT"; 
    do{
        bool flag = true; 
        for(int index = 0; index < people.length(); index++){
            if(!check(index, people)){
                flag = false; 
                break;                
            }
        }
        if(flag) answer++; 
    } while(next_permutation(people.begin(), people.end())); 
    return answer; 
}
