#include <stdio.h>
#pragma warning(disable : 4996)
#include <math.h>

void move(int N, int start, int to) {
	printf("%d %d\n", start, to);
}

void hanoi(int N, int start, int to, int via) {
	if (N == 1)
		move(1, start, to);
	else {
		hanoi(N - 1, start, via, to);
		move(N, start, to);
		hanoi(N - 1, via, to, start);
	}
}

int main() {
	int N; // 원반 개수 
	scanf("%d", &N);
	int result = pow(2, N) - 1;
	printf("%d\n", result);
	hanoi(N, 1, 3, 2);

	return 0;
}