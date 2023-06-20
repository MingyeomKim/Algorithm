#include <string>
#include <vector>

using namespace std;

void recursive(int index, int sum, vector<int> numbers, int target, int &answer){
    if(index == numbers.size() - 1){
        if(target == sum) answer++; 
        return;
    }
    recursive(index + 1, sum + numbers[index], numbers, target, answer); 
    recursive(index + 1, sum - numbers[index], numbers, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    numbers.push_back(0);
    recursive(0, 0, numbers, target, answer);
    return answer;
}