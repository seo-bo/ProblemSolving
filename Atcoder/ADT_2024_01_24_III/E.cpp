#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll> s(n), t(n);
	for (auto& i : s)
	{
		cin >> i;
	}
	for (auto& i : t)
	{
		cin >> i;
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int nxt = (j + 1) % n;
			if (t[nxt] > t[j] + s[j])
			{
				t[nxt] = t[j] + s[j];
			}
		}
	}
	for (auto& i : t)
	{
		cout << i << '\n';
	}
	return 0;
}
