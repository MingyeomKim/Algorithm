#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

double circle(int x, int d){
    return sqrt((double)d * d - (double) x * x);
}

long long solution(int k, int d) {
    long long answer = 0;
    int max = d / k;
    for(int a = 0; a <= max; a++){
        int max_b = circle(a * k, d);
        answer += (max_b / k + 1);
    }
    
    return answer;
}