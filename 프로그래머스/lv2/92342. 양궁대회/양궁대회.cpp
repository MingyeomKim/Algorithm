#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int calcDiff(vector<int> a, vector<int> b){
    int sum1 = 0, sum2 = 0; 
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 0 && b[i] == 0) continue;
        if(a[i] >= b[i]) sum1 += (10 - i);
        else sum2 += (10- i);
    }
    return sum2 - sum1;
}

void getCandidates(int index, int cnt, int n, vector<int> info, vector<int> & selected, vector<pair<int, vector<int>>> &result) {
    if(index == info.size()){
        if(cnt >= n) {
            int diff = calcDiff(info, selected);
            if(diff > 0) result.emplace_back(diff, selected);
        } else {
            selected[selected.size() - 1] = n - cnt;
            int diff = calcDiff(info, selected); 
            if(diff > 0) result.emplace_back(diff, selected);
        }
        return ;
    }
    if(cnt + info[index] + 1 <= n){
        selected[index] = info[index] + 1;
        getCandidates(index + 1, cnt + selected[index], n, info, selected, result);
    }
    selected[index] = 0;
    getCandidates(index + 1, cnt, n, info, selected, result);
}

bool cmp(pair<int, vector<int>> &a , pair<int, vector<int>> & b){
    if(a.first == b.first){
        for(int i = a.second.size() - 1; i >= 0; i--){
            if(a.second[i] == 0 && b.second[i] == 0) continue;
            if(a.second[i] == 0 && b.second[i] != 0)
                return false; 
            else if (a.second[i] != 0 && b.second[i] == 0)
                return true; 
            else return a.second[i] > b.second[i];
        }
    }else 
        return a.first > b.first;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    vector<int> selected(11);
    vector<pair<int, vector<int>>> candidates;
    getCandidates(0, 0, n, info, selected, candidates);
    
  
    if(candidates.empty()) answer.push_back(-1); 
    else {
        sort(candidates.begin(), candidates.end(), cmp);
        answer = candidates[0].second; 
    }
    return answer;
}