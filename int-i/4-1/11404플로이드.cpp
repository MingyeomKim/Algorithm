#include <iostream>
using namespace std;
#define MAX 101
#define INF 987654321

int arr[MAX][MAX]; // 정점의 개수만큼 이차원 배열 생성
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
	cin >> n; // 정점
	cin >> m; // 간선
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;  // INF 값으로 초기화
		}
	}

	for (int i = 0; i < m; i++) { // 정점 간의 가중치 입력
		int from, to, weight; 
		cin >> from >> to >> weight;
		if (arr[from][to] > weight) // 최단거리로 저장
			arr[from][to] = weight;
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || arr[i][j] == INF) // 같거나 바로 연결할 수 없는 지점이라면 
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}