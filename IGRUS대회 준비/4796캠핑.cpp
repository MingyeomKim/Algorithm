#include <iostream>
using namespace std;

int main()
{
	int day_all, day_use, vac;
	int i = 0;
	while (1)
	{
		int answer = 0;
		i++;
		cin >> day_use >> day_all >> vac;
		if (day_use == 0 && day_all == 0 && vac == 0)
		{
			break;
		}
		answer = (vac / day_all) * day_use;
		int a = vac % day_all;
		if (a > day_all)
		{
			answer += (a / day_all) * day_use;
		}
		else if (a < day_all && a >= day_use)
		{
			answer += day_use;
		}
		else //a가 day_use보다 작은 경우
		{
			answer += a;
		}
		cout << "Case " << i << ": " << answer << endl;
	}

	return 0;
}

//if문은 굳이 안넣어도 되는 것이다. 왜냐하면 a, 즉 vac %  day_all은 항상 day_all보다 작기 때문에
//if문은 영원히 작동되지 않는 것이다. 
