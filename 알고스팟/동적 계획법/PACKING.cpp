#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, w;
string name[101];
int need[101], volume[100];
int cache[1001][101];

// 만들어질 수 있는 조합의 절박도의 최댓값 반환
int pack(int capacity, int item) {
	if (item == n) return 0; 
	
	int& ret = cache[capacity][item];
	if (ret != -1) return ret; 

	// if (volume[item] > capacity) // 넣을 수 없는 경우
	ret = pack(capacity, item + 1);
	if(volume[item] <= capacity)
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);

	return ret; 
}

int sum = 0;
void reconstruct(int capacity, int item, vector<string>& list) {
	if (item == n) return;
	// item 번째 물건이 선택되었는지 확인
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, list);
	else {
		list.push_back(name[item]);
		sum += need[item]; 
		reconstruct(capacity - volume[item], item + 1, list); 
	}
}


int main() {
	int cases; cin >> cases;
	while (cases--) {
		cin >> n >> w;
		for (int i = 0; i < 101; i++) name[i] = "";
		memset(need, 0, sizeof(need));
		memset(volume, 0, sizeof(volume));
		memset(cache, -1, sizeof(cache));
		sum = 0; 

		for (int i = 0; i < n; i++)
			cin >> name[i] >> volume[i] >> need[i];

		vector<string> list; 
		reconstruct(w, 0, list);
		cout << sum << " " << list.size() << endl;
		for (int i = 0; i < list.size(); i++)
			cout << list[i] << endl;
	}
	return 0; 
}