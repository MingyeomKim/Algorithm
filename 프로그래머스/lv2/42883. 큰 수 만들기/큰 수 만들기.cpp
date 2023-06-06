#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[1000001]; 

string solution(string number, int k) {
    string answer = ""; 
    for(int i = 0; i < number.length(); i++){
        bool flag = true; // 현재 숫자를 선택해도 되는지 ? 
        for(int j = 1; j <= k; j++){
            if(number[i]  < number[i + j]) {
                flag = false; 
                k--; 
                break;
            }
        }
        if(flag)
            answer.push_back(number[i]);
    }
    while(k != 0){
        answer.pop_back();
        k--; 
    }
    return answer;
}