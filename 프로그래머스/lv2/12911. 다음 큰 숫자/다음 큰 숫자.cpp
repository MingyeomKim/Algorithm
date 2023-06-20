#include <string>
#include <vector>
#include <iostream>

using namespace std;

int bitSize(int x){
    int ret = 0; 
    while(x != 0){
        x /= 2; 
        ret++;
    }
    return ret; 
}

int bitCount(int x){
    int k = bitSize(x); 
    int ret = 0; 
    while(x){
        ret += x & 1; 
        x >>= 1; 
    }
    return ret; 
}

int solution(int n) {
    int answer = 0;
    int temp = bitCount(n); 
    for(int i = n + 1;; i++){
        if(temp == bitCount(i)){
            answer = i; 
            break;
        }
    }
    return answer;
}