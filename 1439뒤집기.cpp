#include <iostream>
using namespace std;



int main()
{
	int cnt1 = 0, cnt0 = 0;
	char s[1000000];
	cin >> s;
	if (s[0] == '1')
		cnt1++;
	else
		cnt0++;

	int i = 0;
	while (s[i + 1] != NULL)
	{
		if (s[i] == s[i + 1])
		{
			i++;
			continue;
		}
		else
		{
			if (s[i + 1] == '0')
				cnt0++;
			else
				cnt1++;
		}
		i++;
	}

	if (cnt1 >= cnt0)
		cout << cnt0 << endl;
	else
		cout << cnt1 << endl;

	return 0;
}
