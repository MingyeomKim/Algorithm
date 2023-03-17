#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int m, q; 
double B[501];  // �� �ܾ ó���� ������ Ȯ��
double T[501][501]; // i�� �ܾ��� ���� �ܾ j�� �ܾ��� Ȯ��
double M[501][501]; // i�� �ܾ ���� ������ j�� �ܾ�� �з��� Ȯ��

string W[501];
int n; // �ν� ����� �ܾ� ��
int R[101]; // �ν� ����� �� �ܾ ��ȣ�� ��ȯ�� �� 
double cache[101][501]; // Q[s-1] = p�� �� Q[s]�� ���� �����Ѵ�.
int choice[101][501]; 

// Q[s-1] = p�� �� Q[s..]�� ������ ä����
// i = s ~ n-1������ g[Q[i]]�� ���� �ִ� = P(R|Q) P(Q) 
double recognize(int segment, int previousMatch) {
	if (segment == n) return 0; 
	
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200; // ���� ���Ѵ�� ���� (�ִ��� ã�� �����Ƿ�)
	int &choose = choice[segment][previousMatch];

	for (int thisMatch = 1; thisMatch < m + 1; thisMatch++) {
		double cand = T[previousMatch][thisMatch]
			+ M[thisMatch][R[segment]]
			+ recognize(segment + 1, thisMatch);
		if (ret < cand) {
			ret = cand; 
			choose = thisMatch; 
		}
	}
	return ret; 
}

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch]; 
	string ret = W[choose];
	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment + 1, choose);
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> q;
	for (int i = 1; i < m + 1; i++)
		cin >> W[i];

	for (int i = 1; i < m + 1; i++) {
		cin >> B[i];
		B[i] = log(B[i]);
	}
	for (int i = 0; i < m + 1; i++)
		for (int j = 1; j < m + 1; j++) {
			if (i == 0)
				T[i][j] = B[j];
			else{
				cin >> T[i][j]; 
				T[i][j] = log(T[i][j]);
			}
		}
	for (int i = 1; i < m + 1; i++)
		for (int j = 1; j < m + 1; j++) {
			cin >> M[i][j]; 
			M[i][j] = log(M[i][j]); 
		}
	while (q--) {
		cin >> n;
		for(int i =0; i < n; i++)
			for (int j = 0; j <= m; j++) {
				cache[i][j] = 1.0; 
			}
		for (int i = 0; i < n; i++) {
			string input;
			cin >> input;
			for (int j = 1; j < m + 1; j++)
				if (W[j] == input) {
					R[i] = j;
					break;
				}
		}
		recognize(0, 0);
		cout << reconstruct(0, 0) << endl;
	}
	return 0; 
}