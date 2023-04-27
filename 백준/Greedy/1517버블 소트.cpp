#include <iostream>
using namespace std;

int num[500001];
int n;
int sorted[500001]; 
long long ret = 0; 

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k = left; 
	while (i <= mid && j <= right) {
		if (num[i] <= num[j]) 
			sorted[k++] = num[i++];
		else {
			sorted[k++] = num[j++];
			ret += (long long) (mid - i + 1); 
		}
	}

	while (i <= mid)
		sorted[k++] = num[i++]; 
	while (j <= right)
		sorted[k++] = num[j++]; 

	for (int i = left; i <= right; i++)
		num[i] = sorted[i];
}

void mergeSort(int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, right);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	mergeSort(0, n - 1); 
	cout << ret << endl;
	return 0;
}