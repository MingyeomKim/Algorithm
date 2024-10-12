#include <string>
#include <vector>
#include <map> 
#include <algorithm>
using namespace std;

int have[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 1; i <= 30; i++) {
        have[i] = 1;
    }

    for (int x : lost) { // 2 4
        have[x] = 0;
    }

    for (int x : reserve) {
        have[x]++;
    }

    int cnt = 0; // 증가된 수업 참가 가능한 학생 수 
    for (int x : reserve) {
        // 1 2 3 4 5
        // t f t f t
        if (have[x] == 2) { // 빌려줄 수 있는 상태
            if (x != 1 && have[x - 1] == 0) {
                cnt++;
                have[x - 1] = 1;
                have[x]--;
            }
            else if (x != n && have[x + 1] == 0) {
                cnt++;
                have[x + 1] = 1;
                have[x]--;
            }
        }
        else if (have[x] == 1) { // 여벌 옷 하나를 잃어버린 상태
            cnt++;
        }
    }

    answer = n - lost.size() + cnt; // 5 - 2 + 1;

    return answer;
}