#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Result = vector<pair<int, int>>;

int n; 

struct Building {
	int from; 
	int to; 
	int height; 
};

bool cmp(Building& u, Building& v) {
	if (u.from == v.from) return u.to < v.to;
	else return u.from < v.from; 
}

void append(Result& ret, pair<int, int>p) {
	int n = ret.size(); 
	if (n > 0) {
		// ���̰� ���� ���� �������� �ִٸ� ���� ���� �߰����� �ʴ´�. 
		if (ret[n - 1].second == p.second)
			return;
		// x��ǥ�� ���� ���� �ִٸ� �� ���� ������ ���̸� �����Ѵ�.
		if (ret[n - 1].first == p.first) {
			ret[n - 1].second = p.second; 
			return; 
		}
	}
	ret.push_back(p); 
}

// �ǹ��� ���ǿ� �°� ��ģ��. 
Result merge(Result & left, Result &right) {
	Result ret; 
	int i = 0, j = 0;
	int h1 = 0, h2 = 0; // ��ī�̶��� 1, 2�� ���� ����

	// ���� �� �߿��� height�� ���� �� �� �տ� ���� �����Ѵ�. 
	while (i < left.size() && j < right.size()) {
		auto& u = left[i], v = right[j];
		if (u.first < v.first) { // right�� x��ǥ�� �� �ڿ� �ִٸ�
			int x = u.first; 
			h1 = u.second; 
			int h = max(h1, h2); // ���� �� ��ī�̶����� ���� �� ū �Ϳ� ���� ���� ��ī�̶����� ���̰� �����ȴ�. 
			append(ret, make_pair(x, h)); 
			i++; 
		}
		else { // left�� x��ǥ�� �� �ڿ� �ִٸ� 
			int x = v.first; 
			h2 = v.second; 
			int h = max(h1, h2); 
			append(ret, make_pair(x, h)); 
			j++; 
		}
	}

	while (i < left.size()) {
		append(ret, left[i]); 
		i++; 
	}
	while (j < right.size()) {
		append(ret, right[j]); 
		j++; 
	}

	return ret; 
}

// Building ����ü �迭�� (������, ����) (����, ����) ���·� �����Ѵ�. 
Result merge_sort(vector<Building>& a,  int left, int right) {
	if (left == right) { 
		Result ret = {
			{a[left].from, a[left].height},
			{a[left].to, 0}
		};
		return ret; 
	}
	int mid = (left + right) / 2;
	auto l = merge_sort(a, left, mid); 
	auto r = merge_sort(a, mid + 1, right); 
	return merge(l, r); 
}


int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 

	cin >> n; 
	vector<Building> a(n); 
	for (int i = 0; i < n; i++)
		cin >> a[i].from >> a[i].height >> a[i].to; 

	// from�� �������� ����
	sort(a.begin(), a.end(), cmp); 

	auto ret = merge_sort(a, 0, n - 1); 
	for (auto& p : ret)
		cout << p.first << " " << p.second << " "; 
	cout << endl;
	return 0; 
}