#include <iostream> 
#include <vector>
#include <cstring>
using namespace std; 

int h, w; int n;

// a, b ��ƼĿ�� �����̿� �ٿ��� �� ����. ���� �� ���� ��� -1�� ��ȯ
int getArea(pair<int, int> a, pair<int,int> b){
	// rotation
	int ret = 0; 
	for (int r1 = 0; r1 < 2; r1++) {
		for (int r2 = 0; r2 < 2; r2++) {
			// ���η� ���̴� ��� (a, b�� ���� ������ ���� H���� �����Ƿ�) 
			if (a.first + b.first <= h && max(a.second, b.second) <= w) {
				int cand = a.first * a.second + b.first * b.second;
				if (ret < cand) ret = cand;
			}
			// ���η� ���̴� ���
			if (a.second + b.second <= w && max(a.first, b.first) <= h) {
				int cand = a.first * a.second + b.first * b.second; 
				if (ret < cand) ret = cand; 
			}
			swap(b.first, b.second);
		}
		swap(a.first, a.second); 
	}
	return ret; 
}

int main() {
	cin >> h >> w >> n; 
	vector<pair<int, int>> sticker;
	for (int i = 0; i < n; i++) {
		int r, c; cin >> r >> c; 
		sticker.emplace_back(r, c); 
	}

	// �� ��ƼĿ�� ��� Ž��
	int ret = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cand = getArea(sticker[i], sticker[j]); 
			if (ret < cand) ret = cand; 
		}
	}
	cout << ret << endl;
	return 0; 
}