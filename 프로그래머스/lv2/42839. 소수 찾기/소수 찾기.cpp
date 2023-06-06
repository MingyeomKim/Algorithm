#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false; 
    }
    return true; 
}

bool visited[10000000]; 
int solution(string numbers) {
    int answer = 0;
    memset(visited, false, sizeof(visited)); 
    sort(numbers.begin(), numbers.end()); 
    int len = numbers.length(); 
    do{
        for(int i = 1; i <= len; i++){
            int n = stoi(numbers.substr(0, i)); 
            if(isPrime(n) && !visited[n]) answer++; 
            visited[n] = true; 
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}