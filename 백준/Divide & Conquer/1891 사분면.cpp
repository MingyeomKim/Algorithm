#include <iostream>
#include <string>
using namespace std; 

int d; 
long long dr, dc; 
string s; 

// (r, c)에서 시작해서 size 크기인 칸을 4등분한다.
// index는 string s를 탐색하는 포인터이다. 
pair<long long, long long> toCoordinate(int index, long long r, long long c, long long size) {
	if (size == 1) return make_pair(r, c); 
	else {
		if (s[index] == '1')
			return toCoordinate(index + 1, r, c + size / 2, size / 2);
		else if (s[index] == '2')
			return toCoordinate(index + 1, r, c, size / 2);
		else if (s[index] == '3')
			return toCoordinate(index + 1, r + size / 2, c, size / 2);
		else if (s[index] == '4')
			return toCoordinate(index + 1, r + size / 2, c + size / 2, size / 2);
	}
	return make_pair(0, 0); 
}

// (r, c)에서 시작해서 pow(2, size) 크기의 칸을 4등분한다. 
// (x, y)로 도착하는 것이 목표
string toNumber(long long r, long long c, long long size, long long x, long long y) {
	if (size == 1) return ""; 
	long long m = size / 2; 

	if (x < r + m && y < c + m)
		return "2" + toNumber(r, c, m, x, y);
	else if (x < r + m && y >= c + m)
		return "1" + toNumber(r, c + m, m, x, y);
	else if (x >= r + m && y < c + m)
		return "3" + toNumber(r + m, c, m, x, y);
	else
		return "4" + toNumber(r + m, c + m, m, x, y); 
}

int main() {
	cin >> d >> s; 
	cin >> dc >> dr; 
	long long size = (1LL << d); 
	auto p = toCoordinate(0, 0, 0, size); 
	dr = -dr; 
	p.first += dr; 
	p.second += dc; 
	if (0 <= p.first && p.first < size && 0 <= p.second && p.second < size)
		cout << toNumber(0, 0, size, p.first, p.second) << endl;
	else
		cout << -1 << endl;
	return 0; 
}