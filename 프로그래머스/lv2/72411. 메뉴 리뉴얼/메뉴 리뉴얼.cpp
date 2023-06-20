#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set> 
#include <iostream>
using namespace std;

void findCombination(string order, int index, string& result, set<set<char>>& combinations) {
    if (index == order.size()) {
        if (result.size() >= 2){
            set<char> s;
            for(char c : result)
                s.insert(c); 
            combinations.insert(s); 
        }
        return;
    }
    result.push_back(order[index]);
    findCombination(order, index + 1, result, combinations);
    result.pop_back();
    findCombination(order, index + 1, result, combinations);
}

string make_string(const set<char> s){
    string result = ""; 
    for(char c : s)
        result.push_back(c); 
    sort(result.begin(), result.end()); 
    return result; 
}

vector<string> solution(vector<string> orders, vector<int> course) {

    set<set<char>> combinations;
    for (string order : orders) {
        string result; 
        findCombination(order, 0, result, combinations);
    }
    
    // 각 조합이 주문된 횟수를 구한다. 
    map<set<char>, int> mp;
    for (auto& p : mp)
        p.second = 0;

    for (auto combi : combinations) {
        for (string order : orders) {
            bool flag = true;
            for(char c : combi){
                if(order.find(c) == string::npos) {
                    flag = false; 
                    break;
                }
            }
            if(flag) mp[combi]++;
        }
    }

    // 각 조합이 등장한 횟수의 최댓값을 구한다.
    vector<string> answer;
    for(int x : course){
        int max = 0;
        vector<string> tmp; 
        cout << "x : " << x << endl;
        for (const auto& p : mp) {
            if (p.first.size() == x) {
                if (p.second > max) {
                    max = p.second;
                    tmp.clear();
                    if(mp[p.first] >= 2)
                        tmp.push_back(make_string(p.first));
                }
                else if (p.second == max){
                     if(mp[p.first] >= 2)
                        tmp.push_back(make_string(p.first));
                }
            }
        }
        
        for(string s : tmp)
            answer.push_back(s);
    }
    sort(answer.begin(), answer.end()); 
    return answer;
}