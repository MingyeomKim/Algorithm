#include <iostream>
using namespace std;
#define MAX 101
#define INF 987654321

int arr[MAX][MAX]; // ������ ������ŭ ������ �迭 ����
int n; int m; 

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] != INF && arr[i][k] != INF) {
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}
}

int main() {
	cin >> n; // ����
	cin >> m; // ����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;  // INF ������ �ʱ�ȭ
		}
	}

	for (int i = 0; i < m; i++) { // ���� ���� ����ġ �Է�
		int from, to, weight; 
		cin >> from >> to >> weight;
		if (arr[from][to] > weight) // �ִܰŸ��� ����
			arr[from][to] = weight;
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || arr[i][j] == INF) // ���ų� �ٷ� ������ �� ���� �����̶�� 
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}