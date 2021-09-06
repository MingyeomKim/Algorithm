#include <iostream>
#include <cmath>
using namespace std;

int main()
{

		int x; cin >> x;
		int index = 0;
		int temp = x;
		int i = 1;
		int son, mom;
		while (true) //x = 5
		{
			temp -= i;
			index++; i++;
			if (temp <= 0)
				break;
		} //index = 3

		int a = (pow(index, 2) - index + 2) / 2;

		if (index % 2 == 0)
		{
			son = x - a + 1;
			mom = index - (x - a);
		}
		else
		{
			son = index - (x - a);
			mom = x - a + 1;
		}

		cout << son << "/" << mom << endl;
    return 0;
    }
