#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> list;
vector<bool> visit;
int answer = 0;

void dfs(int x)
{
	answer++;
	visit[x] = true;

	for (int i = 0;i < int(list[x].size()); i++)
	{
		if (!visit[list[x][i]])
			dfs(list[x][i]);
	}
}

int main()
{
	int computers; cin >> computers;
	int connect; cin >> connect; //연결된 컴퓨터 쌍의 개수
	int a, b;
	/*
	for (int i = 0;i < connect; i++)
	{
		list[i][0] = 0;
	} //연결리스트의 첫번째 요소를 default값으로 설정
	*/
	visit.resize(computers + 1);
	list.resize(computers + 1); //list의 사이즈 8로 지정
	for (int i = 0; i < connect; i++)
	{
		cin >> a >> b;
		list[a].push_back(b); // 벡터의 a번째 위치에 원소 b를 넣는다. 
		list[b].push_back(a);
	}
	// 이중 벡터에 연결리스트가 생성되었다.

	dfs(1);
	cout << answer - 1;
	return 0;
}

/*
* 
	
	cout << list[1].size() << endl;
	for (int i = 0;i < connect; i++)
	{
		for (int j = 0; i < int(list[i].size()); i++)
		{
			cout << list[i][j] << " ";
		}
		cout << endl;
	}

	answer.push_back(1); //1을 기본 세팅으로 넣는다.
	cout << answer.size() << endl;
	for (int i = 1;i <= int(answer.size());i++)
	{
		cout << "i: " << i << " list[i].size : " << list[i].size() << endl;
		for (int j = 1; j <= int(list[i].size()); j++)
		{
			if (!find(list[answer[i]][j],answer)) //넣으려는 노드가 answer에 없으면
			{
				answer.push_back(list[answer[i]][j]);
				cout << "list[answer[i]][j] : " << list[answer[i]][j] << "push backed" << endl;
			}
		}
	}

	cout << answer.size() - 1<< endl; //1을 제외하고 answer의 사이즈를 반환
*/
