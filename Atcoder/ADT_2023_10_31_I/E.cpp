#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>mm;
	string A, B;
	cin >> A >> B;
	int a = 0, b = 0;
	for (auto& i : A)
	{
		if (i == '@')
		{
			a++;
			continue;
		}
		mm[i]++;
	}
	for (auto& i : B)
	{
		if (i == '@')
		{
			b++;
			continue;
		}
		if (--mm[i] == 0)
		{
			mm.erase(i);
		}
	}
	string base = "atcoder";
	int sum = 0;
	for (auto& [pa, pb] : mm)
	{
		int flag = 0;
		for (auto& i : base)
		{
			if(i == pa)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			cout << "No";
			return 0;
		}
		if (pb > 0)
		{
			if (pb > b)
			{
				cout << "No";
				return 0;
			}
			int temp = min(pb, b);
			pb -= temp, b -= temp;
		}
		else
		{
			pb = -pb;
			if (pb > a)
			{
				cout << "No";
				return 0;
			}
			int temp = min(pb, a);
			pb -= temp, a -= temp;
		}
	}
	cout << ((a != b) ? "No" : "Yes");
	return 0;
}
