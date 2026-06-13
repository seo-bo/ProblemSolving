#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MAX 100000

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>div(MAX + 1);
	iota(div.begin(), div.end(), 0);
	for (ll i = 2; i * i <= MAX; ++i)
	{
		if (div[i] == i)
		{
			for (ll j = i * i; j <= MAX; j += i)
			{
				if (div[j] == j)
				{
					div[j] = i;
				}
			}
		}
	}
	vector<int>res;
	while (n--)
	{
		int x = 0;
		cin >> x;
		while (x > 1)
		{
			int d = div[x];
			res.push_back(d);
			while (x % d == 0)
			{
				x /= d;
			}
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	vector<int>ans(MAX + 1, 1);
	for (auto& i : res)
	{
		for (ll j = i; j <= MAX; j += i)
		{
			ans[j] = 0;
		}
	}
	vector<int>p;
	for (int i = 1; i <= m; ++i)
	{
		if (ans[i])
		{
			p.push_back(i);
		}
	}
	cout << p.size() << '\n';
	for (auto& i : p)
	{
		cout << i << '\n';
	}
	return 0;
}
