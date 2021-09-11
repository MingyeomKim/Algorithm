#include <iostream>
#include <cstring>
using namespace std;


int *que; // 스택 포인터
int ptr= 0;// 스택 현재 위치

void push(int num)
{
	que[ptr++] = num;
}

void pop() {
	if (ptr <= 0)
		cout << -1 << endl;
	else {
		cout << que[--ptr] << endl;
	}
}

void size() {
	cout << ptr << endl;
}

void empty() {
	if (ptr <= 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

void top() {
	if (ptr <= 0)
		cout << -1 << endl;
	else
		cout << que[ptr -1] << endl; 
}

int main()
{
	que = new int[10001]; // 최대 push 횟수
	int n; cin >> n; // 횟수
	string command;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") {
			int num; cin >> num;
			push(num);
		}
		else if (command == "pop")
			pop();
		else if (command == "size")
			size();
		else if (command == "empty")
			empty();
		else
			top();
	}

	return 0;
}
