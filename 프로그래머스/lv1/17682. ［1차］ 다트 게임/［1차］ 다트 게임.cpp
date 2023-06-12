#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> dart;
    for(int i =0; i < dartResult.length(); i++){
        string number = ""; 
        while(true){
            if(isdigit(dartResult[i]))
                number.push_back(dartResult[i]); 
            else
                break;
            i++;
        }
        int score = stoi(number); 
        char bonus = dartResult[i];
        if(bonus == 'D') score *= score; 
        else if(bonus == 'T') score = score * score * score;
        
        if(i < dartResult.length() - 1 && !isdigit(dartResult[i + 1])){
            i++; 
            if(dartResult[i] == '*'){
                if(dart.empty()){
                    score *= 2;
                } else{
                    int c = dart.size(); 
                    dart[c - 1] *= 2; 
                    score *= 2;
                }
            } else {
                score *= -1;
            }
        }
        dart.push_back(score); 
    }
    for(int x : dart){
        answer += x;
    }
    return answer;
}