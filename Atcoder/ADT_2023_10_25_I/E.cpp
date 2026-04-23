#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	map<ll, ll>mm, parent;
	queue<ll>q;
	q.push(n);
	mm[n] = 0;
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		if (mm[cur] == 120 || !cur)
		{
			continue;
		}
		if (cur % 2 == 0)
		{
			ll t = cur / 2;
			if (mm.find(t) == mm.end() || mm[t] > mm[cur] + 1)
			{
				mm[t] = mm[cur] + 1;
				parent[t] = cur;
				q.push(t);
			}
		}
		ll t = cur - 1;
		if (mm.find(t) == mm.end() || mm[t] > mm[cur] + 1)
		{
			mm[t] = mm[cur] + 1;
			parent[t] = cur;
			q.push(t);
		}
	}
	ll x = 0;
	while (x != n)
	{
		if (x + 1 == parent[x])
		{
			cout << "A";
		}
		else
		{
			cout << "B";
		}
		x = parent[x];
	}
	return 0;
}
