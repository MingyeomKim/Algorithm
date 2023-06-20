#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Day{
public:
    int year; 
    int month; 
    int day; 
    Day(int y, int m, int d) : year(y), month(m), day(d)
        {}
    bool operator > (const Day & other){
        if(year == other.year) {
            if(month == other.month) return day > other.day;
            else return month > other.month;
        } else
            return year > other.year;
    }
};

// today에서 month 개월이 지났을 때의 날짜를 Day 구조체로 만들어 반환
Day calculate(const Day today, int month){
    Day end(today.year, today.month, today.day);
    

    if(end.month + month > 12){
        for(int i = 0; i < month / 12; i++)
            end.year++;
        for(int i = 0; i < month % 12; i++){
            if(end.month == 12) {
                end.year++; 
                end.month = 1;
            } else 
                end.month++;
        }
    } else 
        end.month = today.month + month;
    
       // cout << end.year<<"/" << end.month << "/" << end.day << endl;
    
    if(end.day == 1){
        if(end.month == 1) {
            end.year--; 
            end.month = 12;
        } else 
            end.month--;
        end.day = 28;  
    }  
    else end.day--;
    
    return end;
}

Day parse(string s){
    int year = stoi(s.substr(0, 4)); 
    int month = stoi(s.substr(5, 2)); 
    int day = stoi(s.substr(8, 2)); 
    return Day(year, month, day);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    Day current = parse(today);
    
    map<char, int> m;
    for(string s : terms){
        char type = s[0];
        string number; 
        for(int i = 2; i < s.length(); i++)
            number.push_back(s[i]); 
        m.insert({s[0], stoi(number)});
    }
    
    for(int i = 0;i < privacies.size(); i++){
        string s = privacies[i];
        
        Day start = parse(s.substr(0, 10)); 
        char type = s[11]; 
        
        Day end = calculate(start, m[type]);
        if(current > end) answer.push_back(i + 1);
    }
    return answer;
}
