#include <iostream>
#include <algorithm>
using namespace std;
#define N 100
#define M 5000
#define INF 

int Min(int A, int B) {
	if (A < B) return A; 
	return B;
}

int n; // 친구의 수
int m; // 친구 관계의수
int adj[N][N];  // 친구 관계를 나타내는 그래프

void initAdj() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) adj[i][j] = 0; 
		}
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue; 
				else if (adj[i][k] != 0 && adj[k][j] != 0) {
					if (adj[i][j] == 0)
						adj[i][j] = adj[i][k] + adj[k][j];
					else 
						adj[i][j] = Min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
	}
}

 
int MinPerson()
{
    int Result = 999999;
    int Person = 1;
    for (int i = 1; i <= n; i++)
    {
        int Tmp_Result = 0;
        for (int j = 1; j <= n; j++)
        {
            Tmp_Result = Tmp_Result + adj[i][j];
        }
 
        if (Result > Tmp_Result)
        {
            Result = Tmp_Result;
            Person = i;
        }
    }
    return Person;
}

int main() {
	cin >> n; cin >> m; 

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	floyd();
	
	cout << MinPerson() << endl;
	return 0; 
}