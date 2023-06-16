#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

void pushMap(map<string, vector<int>> & mp, vector<string> &v, vector<string> &s, int index){
    if(index == 4){
        mp[s[0] + s[1] + s[2] + s[3]].push_back(stoi(v[4]));
        return ;
    }
    s.push_back(v[index]); 
    pushMap(mp, v, s, index + 1); 
    s.pop_back(); 
    s.push_back("-");
    pushMap(mp, v, s, index + 1); 
    s.pop_back();
}

void replace_all(std::string& str, const std::string& old_value, const std::string& new_value) {
    size_t pos = 0;
    while ((pos = str.find(old_value, pos)) != std::string::npos) {
        str.replace(pos, old_value.length(), new_value);
        pos += new_value.length();
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    map<string, vector<int>> mp; 
    for(string person : info){
        vector<string> v(5);
        stringstream ss(person);
        ss >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
        
        vector<string> s;
        pushMap(mp, v, s, 0);
    }
    
    // 정렬
    for(auto &p : mp){
        vector<int> &v =  p.second; 
        sort(v.begin(), v.end());
    }
    
    for(string s : query ){
        replace_all(s, " and ", "");
        
        string tmp = "";
        while(s.back() <= '9' &&  s.back() >= '0'){
            tmp = s.back() + tmp; 
            s.pop_back();
        }
        s.pop_back(); 
        int min_score = stoi(tmp);
        
        if(mp.find(s) == mp.end()) {
            answer.push_back(0);
            continue;
        }
        
        // 이분 탐색
        vector<int> scores = mp[s]; 
        int left = 0, right = scores.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(scores[mid] <  min_score) 
                left = mid + 1; 
            else
                right = mid - 1;
        }
        answer.push_back(scores.size() - left);
    }
    return answer;
}

