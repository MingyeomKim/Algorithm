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
		// 높이가 같은 것이 연속으로 있다면 현재 점을 추가하지 않는다. 
		if (ret[n - 1].second == p.second)
			return;
		// x좌표가 같은 것이 있다면 더 높은 것으로 높이를 갱신한다.
		if (ret[n - 1].first == p.first) {
			ret[n - 1].second = p.second; 
			return; 
		}
	}
	ret.push_back(p); 
}

// 건물을 조건에 맞게 합친다. 
Result merge(Result & left, Result &right) {
	Result ret; 
	int i = 0, j = 0;
	int h1 = 0, h2 = 0; // 스카이라인 1, 2의 현재 높이

	// 연속 점 중에서 height가 같은 것 중 앞에 것을 제외한다. 
	while (i < left.size() && j < right.size()) {
		auto& u = left[i], v = right[j];
		if (u.first < v.first) { // right의 x좌표가 더 뒤에 있다면
			int x = u.first; 
			h1 = u.second; 
			int h = max(h1, h2); // 현재 두 스카이라인의 높이 중 큰 것에 의해 최종 스카이라인의 높이가 결정된다. 
			append(ret, make_pair(x, h)); 
			i++; 
		}
		else { // left의 x좌표가 더 뒤에 있다면 
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

// Building 구조체 배열을 (시작점, 높이) (끝점, 높이) 형태로 분할한다. 
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

	// from을 기준으로 정렬
	sort(a.begin(), a.end(), cmp); 

	auto ret = merge_sort(a, 0, n - 1); 
	for (auto& p : ret)
		cout << p.first << " " << p.second << " "; 
	cout << endl;
	return 0; 
}