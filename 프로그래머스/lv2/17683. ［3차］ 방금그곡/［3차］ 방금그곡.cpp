#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;

string change(string s, map<string, char> &mp){
    string out = ""; 
    for(int i = 0; i < s.size(); i++){
        if(s[i + 1] == '#'){
            out += mp[s.substr(i, 2)]; 
            i++; 
        } else
            out += s[i]; 
    }
    return out; 
}

int calcRuntime(string start, string end){
    int h1 = stoi(start.substr(0, 2)) * 60 ; 
    int m1 = stoi(start.substr(3, 2)); 
    int h2 = stoi(end.substr(0, 2)) * 60; 
    int m2 = stoi(end.substr(3, 2)); 
    
    return (h2 + m2) - (h1 + m1); 
}

string solution(string m, vector<string> musicinfos) {
    map<string, char> mp; 
    mp["C#"] = 'Q';
    mp["D#"] = 'W';
    mp["F#"] = 'R';
    mp["G#"] = 'T';
    mp["A#"] = 'Y';
    
    string melody = change(m, mp); 
    
    int maxTime = 0; 
    string answer = "(None)"; 
    for(string s : musicinfos){
        /* parsing runtime */ 
        int runtime = calcRuntime(s.substr(0, 5), s.substr(6, 5)); 
        
        /* parsing name */
        string name = ""; 
        int i; 
        for(i = 12; ; i++){
            if(s[i] == ',') break; 
            name += s[i]; 
        }
        
        /* parsing part code */ 
        string code = change(s.substr(i + 1), mp); 
        
        /* make whole code by runtime */
        if(code.length() < runtime) {
            string tmp = code; 
            for(int i = 1; i < runtime / tmp.length(); i++)
                code += tmp; 
            for(int i = 0; i < runtime % tmp.length(); i++)
                code += tmp[i]; 
        } else
            code = code.substr(0, runtime); 
        
        /* find melody in code */ 
        if(code.find(melody) != string::npos)
            if(maxTime < runtime){
                answer = name; 
                maxTime = runtime;
            }
    }
    return answer;
}

/*

1. 재생된 시간을 구해서 음악 코드의 진행을 모두 늘어뜨려 배열에 저장한다. 이때 코드는 모두 숫자로 변환한다.
2. 배열의 길이가 가장 긴 것부터 검사하고, M이 포함된 코드가 있다면 바로 반환한다.
3. 포함된 코드가 없다면 None을 반환한다.
*/