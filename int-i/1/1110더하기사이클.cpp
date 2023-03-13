#include <iostream>
using namespace std;

int input;
int cnt = 1;

void cycle(int n, int m) {
    int result = n * 10 + (m % 10);
    if (result == input)
        return;
    else {
        cnt++;
        int a = result / 10;
        int b = result % 10;
        cycle(b, a + b);
    }
}

int main() {
    cin >> input;
    int a = input / 10;
    int b = input % 10;
    cycle(b, a + b);

    cout << cnt << endl;

    return 0;
}
