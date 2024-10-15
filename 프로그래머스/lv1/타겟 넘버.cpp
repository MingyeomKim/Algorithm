#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int solution(vector<int> numbers, int target) {
    int ret = 0;
    int n = numbers.size();
    queue<pair<int, int>> q;
    q.push(make_pair(0, -1));
    while (!q.empty()) {
        int x, index;
        tie(x, index) = q.front(); // (0, -1),  
        q.pop();
        if (x == target && index == n - 1) { // ���������� �԰� target�� ã�� ���
            ret++;
        }
        // numbers[index + 1] �� +, -
        if (index != n - 1) {
            q.push(make_pair(x + numbers[index + 1], index + 1));
            q.push(make_pair(x - numbers[index + 1], index + 1));
        }
    }
    return ret;
}