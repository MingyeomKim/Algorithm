#include <iostream>
#include <tuple>
#include <queue>
using namespace std; 

int a, b, c;
int sum; 
bool check[201][201]; //  a, b, c(자동으로 값 계산)을 검사하였는 지 저장
bool ret[201]; // 물병 C의 물의 양이 i가 될 수 있다면 ret[i] = true

void dfs(int x, int y, int z) {
	if (check[x][y]) return; 
	if (x == 0) ret[z] = true; 

	check[x][y] = true; 

	// from a to b
	if (x + y > b) dfs(x - b + y, b, z);
	else dfs(0, x + y, z); 
	
	// from a to c 
	if (x + z > c) dfs(x - c + z, y, c);
	else dfs(0, y, x + z); 

	// from b to a
	if (x + y > a) dfs(a, y - a + x, z);
	else dfs(x + y, 0, z); 

	// from b to c
	if (y + z > c) dfs(x, y - c + z, c);
	else dfs(x, 0, y + z); 

	// from c to a
	if (x + z > a) dfs(a, y, z - a + x);
	else dfs(x + z, y, 0); 

	// from c to b
	if (y + z > b) dfs(x, b, z - b + y);
	else dfs(x, y + z, 0);
}


int main() {
	cin >> a >> b >> c; 
	sum = a + b + c; 
	dfs(0, 0, c); 
	for (int i = 0; i < 201; i++)
		if (ret[i]) cout << i << " "; 
	cout << endl;
	return 0; 
}