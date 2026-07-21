#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, q = 0;
	cin >> n >> k >> q;
	vector<int>v(n + 1), pos(k + 1);
	for (int i = 1; i <= k; ++i)
	{
		int a = 0;
		cin >> a;
		v[a] = i;
		pos[i] = a;
	}
	while (q--)
	{
		int a = 0;
		cin >> a;
		int now = pos[a];
		if (now == n)
		{
			continue;
		}
		if (!v[now + 1])
		{
			v[now] = 0;
			v[now + 1] = a;
			pos[a] = now + 1;
		}
	}
	for (int i = 1; i <= k; ++i)
	{
		cout << pos[i] << ' ';
	}
	return 0;
}
