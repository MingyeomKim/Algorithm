#include <string>
#include <vector>

using namespace std;

bool canExpress(int start, int n){
    while(n > 0){
        n -= start;
        start++;
    }
    return n == 0 ? true : false;
}

int solution(int n) {
    int answer = 0;
    for(int start = 1; start <= n; start++){
        if(canExpress(start, n))
            answer++;
    }
    return answer;
}