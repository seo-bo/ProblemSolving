#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>one, two, three;
	int n = 0, w = 0;
	cin >> n >> w;
	for (int i = 0; i < n; ++i)
	{
		int p = 0;
		cin >> p;
		for (auto& [a, b] : two)
		{
			if (a + p <= w)
			{
				three[a + p] += b;
			}
		}
		for (auto& [a, b] : one)
		{
			if (a + p <= w)
			{
				two[a + p] += b;
			}
		}
		if (p <= w)
		{
			one[p]++;
		}
	}
	set<int>s;
	for (auto& [a, b] : one)
	{
		s.insert(a);
	}
	for (auto& [a, b] : two)
	{
		s.insert(a);
	}
	for (auto& [a, b] : three)
	{
		s.insert(a);
	}
	cout << s.size();
	return 0;
}
