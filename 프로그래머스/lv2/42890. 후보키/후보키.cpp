#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> candidates; // 이미 검사한 후보키를 등록한다.

bool isSubset(int target, int previous) {
    return ((target & previous) == previous);
}

bool check_minimality(int target) { // 이전에 등록한 후보키와 겹치면 false
    for (int previous : candidates) {
        if (isSubset(target, previous))
            return false;
    }
    return true;
}

bool check_uniqueness(int i, vector<vector<string>> relation) {
    int k = relation[0].size();
    vector<string> combined;

    for (auto v : relation) {
        string temp = "";
        for (int j = 0; j < k; j++)
            if ((i & (1 << j)) != 0) 
                temp += v[j];
        if (find(combined.begin(), combined.end(), temp) != combined.end())
            return false; 
        else
            combined.push_back(temp);
    }
    return true; 
}

int solution(vector<vector<string>> relation) {
    int k = relation[0].size(); // Attribute의 개수
    for (int i = 1; i < (1 << k); i++) {
        if (check_uniqueness(i, relation) && check_minimality(i)) 
            candidates.push_back(i);
    }
    int answer = candidates.size();
    return answer;
}