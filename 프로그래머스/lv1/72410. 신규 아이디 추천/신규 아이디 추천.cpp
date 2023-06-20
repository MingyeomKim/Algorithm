#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string new_id) {
    
    string tmp;
    for(char c : new_id) {
        if(isupper(c)) tmp.push_back(tolower(c));
        else if((c < 'a' || c > 'z') && c != '-' && c != '_' && c!= '.' && !isdigit(c)) continue;
        else tmp.push_back(c);
    }
    new_id = tmp;
    
    tmp.clear();
    for(int i = 0; i< new_id.length(); i++){ // 3단계
        char c = new_id[i]; 
        if(i > 0 && c == '.' && new_id[i - 1] == '.') continue; 
        else tmp.push_back(c);
    }
    new_id = tmp;
    
    // 4단계
    if(new_id[0] == '.') new_id.erase(new_id.begin()); 
    if(new_id[new_id.length() - 1] == '.') new_id.pop_back(); 
    
    
    if(new_id.length() == 0)  // 5단계
        new_id.push_back('a');
    if(new_id.length() > 15) { // 6단계
        new_id = new_id.substr(0, 15);
        if(new_id.back() == '.') new_id.pop_back();
    }
    if(new_id.length() < 3){ // 7단계
        char c = new_id.back();
        while(new_id.length() != 3)
            new_id.push_back(c);
    } 
    return new_id;
}
