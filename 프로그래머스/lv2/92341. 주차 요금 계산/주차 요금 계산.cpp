#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

int calcTime(string time){
    int h = stoi(time.substr(0, 2));  
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int basic_time, basic_fee, unit_time, unit_fee;
int calcFee(int time) {
    if(time <= basic_time) 
        return basic_fee; 
    else 
        return basic_fee + ceil((double)(time - basic_time) / (double)unit_time) * unit_fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    basic_time = fees[0], basic_fee = fees[1]; 
    unit_time = fees[2], unit_fee = fees[3];

    map<string, vector<int>> mp; 
    set<string> car_list;
    for(string s : records) {
        string time, number, flag; stringstream ss(s);  
        ss >> time >> number >> flag; 
        
        car_list.insert(number); 
        mp[number].push_back(calcTime(time));
    }
    
    vector<pair<string, int>> v;
    for(string car : car_list){
        vector<int> record = mp[car]; 

        int time = 0;
        for(int i = 0; i < record.size() - 1; i += 2)
            time += (record[i + 1] - record[i]); 
        if(record.size() % 2 == 1)
            time += (calcTime("23:59") - record.back());
        v.emplace_back(car, calcFee(time));
    }
    
    sort(v.begin(), v.end()); 
    for(const auto p : v)
        answer.push_back(p.second);
    return answer;
}