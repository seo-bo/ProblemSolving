#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	vector<int>v = { 4,2,1 };
	set<int>s;
	while (a)
	{
		for (auto& i : v)
		{
			if (a >= i)
			{
				s.insert(i);
				a -= i;
			}
		}
	}
	while (b)
	{
		for (auto& i : v)
		{
			if (b >= i)
			{
				s.insert(i);
				b -= i;
			}
		}
	}
	int sum = 0;
	for (auto& i : s)
	{
		sum += i;
	}
	cout << sum;
	return 0;
}
