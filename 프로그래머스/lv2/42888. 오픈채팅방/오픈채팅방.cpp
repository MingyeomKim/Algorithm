#include <string>
#include <vector>
#include <tuple>
#include <map>
using namespace std; 

pair<string,string> parse(string s, int start){
    string id = "", nickname = "";  
    int i; 
    for(i = start; i < s.length(); i++)
        if(s[i] == ' ') break; 
        else id.push_back(s[i]);
    nickname = s.substr(i + 1); 
    return make_pair(id, nickname); 
}

// v에서 세번째 인자가 id인 튜플의 첫번째 인자를 nickname으로 변경한다.
void changeLog(vector<tuple<string,string,string>>& v, map<string, string> mp){
    for(int i =0; i < v.size(); i++){
        string nickname, dummy, id;
        tie(nickname, dummy, id) = v[i]; 
        if(mp[id] != nickname){
            v[i] = make_tuple(mp[id], dummy, id); 
        }
    }
}

vector<string> solution(vector<string> record) { 
    vector<tuple<string, string, string>> v; 
    map<string, string> mp; // id, nickname;
    
    for(string s : record){
        if(s[0] == 'E'){ // Enter
            auto p = parse(s, 6); 
            string id = p.first, nickname = p.second; 
            v.emplace_back(nickname, "님이 들어왔습니다.", id); 
            mp[id] = nickname;
        } else if(s[0] == 'L'){ // Leave
            string id = ""; 
            int i;
            for(int i= 6; i < s.length(); i++)
                id += s[i]; 
            string nickname = mp[id]; 
            v.emplace_back(nickname, "님이 나갔습니다.", id); 
        } else{ // change
            auto p = parse(s, 7); 
            string id = p.first, nickname = p.second; 
            mp[id] = nickname;
        }
    }
    changeLog(v, mp); 
    
    vector<string> answer; 
    for(auto t : v){ 
        string nickname, dummy, id; 
        tie(nickname, dummy, id) = t; 
        answer.push_back(nickname + dummy); 
    }
    return answer; 
}

/*
1. 들어오고 나간 기록을 저장한다.
2. 각 기록에 대해서 누구에 대한 정보인지 유저아이디로 저장한다.
3. Change -> 기록을 탐색하며, 현재 이름으로 변경한다. 
*/