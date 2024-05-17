#include <iostream>
#include <cmath>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

int n;
void solve(int length, bool exists) {
	if (exists && length == 1) {
		cout << "-";
		return;
	}
	if (!exists) {
		for (int i = 0; i < length; i++) {
			cout << " ";
		}
		return;
	}

	solve(length / 3, true);
	solve(length / 3, false);
	solve(length / 3, true);
}

int main() {
	while (scanf("%d", &n) != EOF) {
		solve(pow(3, n), true);
		cout << endl;
	}
	return 0;
}