#include <iostream>
using namespace std;

int weight[200001];
bool check[200001];

int main() {
	int n; cin >> n;
	int max = 0;
	int min = -1; // �Űܾ� �ϴ� �� �� ���� ���� ��
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
		if (max < weight[i]) {
			max = weight[i];
		}
		else if (max > weight[i]) {
			check[i] = true; // �� �Űܾ� ��
			cnt++;
			if (min == -1 || min > weight[i]) {
				min = weight[i];
			}
		}
	}

	max = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (check[i] && max < weight[i]) {
			max = weight[i];
		}
		else if (!check[i] && max > weight[i]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}