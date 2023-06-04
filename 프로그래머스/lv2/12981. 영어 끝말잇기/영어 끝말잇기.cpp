#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void saveAnswer(int n, vector<int> &answer, int i){
    int who = i % n; 
    if(who == 0) who = n;
    answer.push_back(who); 
    answer.push_back((i + n - 1) / n); 
}

bool isOverlapped(vector<string> words, int right){
    string word = words[right]; 
    for(int i = 1;i < right; i++){
        if(words[i] == word) return true;
    }
    return false; 
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    words.insert(words.begin(), "temp value"); 
    for(int i = 2; i < words.size(); i++){
        string last = words[i - 1]; 
        if(last[last.length() - 1] != words[i][0]){
           saveAnswer(n, answer, i);
            break;
        } else if (isOverlapped(words, i)){
            saveAnswer(n, answer, i); 
            break;
        } 
    }
    if(answer.empty()){
        answer.push_back(0); 
        answer.push_back(0); 
    }
    return answer;
}

/*
    주어진 단어들을 순회
    1. K번째 단어를 말한 사람이 틀렸다면, 그 사람은 K % N번(K % N == 0인 경우 K번)이고, K / N 번째로 말한 것이다. 
    2. 앞의 단어의 끝글자와 다른 것을 말하거나, 이미 나왔던 것을 말하면 탈락이다.
*/