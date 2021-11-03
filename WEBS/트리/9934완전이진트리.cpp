//9934 완전 이진 트리
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int k;
vector <int> order;
vector <int> answer[11];

void findCenter(int left, int right, int depth) {
	if (depth == k)
		return;
	if (left == right) {
		answer[depth].push_back(order[left]);
		return;
	}
	int center = (left + right) / 2;
	answer[depth].push_back(order[center]); 
	findCenter( left, center - 1, depth + 1);
	findCenter(center + 1, right, depth + 1); 
}

int main()
{
	cin >> k;
	int size_k = pow(2, k) - 1; // 노드의 개수
	for (int i = 0; i < size_k; i++) {
		int num; cin >> num;
		order.push_back(num);
	} // 1 6 4 3 5 2 7
	
	findCenter(0, order.size(), 0);

	// 깊이에 따라 출력
	for (int i = 0; i < k; i++) { // overflow 에러
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}