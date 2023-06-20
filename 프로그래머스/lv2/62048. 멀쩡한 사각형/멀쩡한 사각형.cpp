#include <cmath>
using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    for(int x = 1; x < w; x++){
        long long n = ((double)h * x) / w;
        answer += n; 
    }
    answer *= 2; 
    return answer; 
}

/*
모든 x축에 대해서 선과 닿는 y축을 찾는다.`
x = 0에서 쓸 수 없는 칸의 개수 : (x = 1)과 맞닿는 x축이 (x + 1)보다 작으면 1개, (x + 2)보다 작고 (x + 1) 보다 크면 2개 .. 이런 식으로 계산한다. 
*/