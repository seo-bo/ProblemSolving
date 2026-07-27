#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii; // 값, left

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	map<int, pii> mm;
	map<int, int> save;
	int now = -1, ver = 0;
	while (q--)
	{
		string str;
		cin >> str;
		if (str == "DELETE")
		{
			if (now == -1)
			{
				cout << -1 << ' ';
				continue;
			}
			now = mm[now].second;
			if (now == -1)
			{
				cout << -1 << ' ';
				continue;
			}
			cout << mm[now].first << ' ';
			continue;
		}
		int a = 0;
		cin >> a;
		if (str == "ADD")
		{
			cout << a << ' ';
			int old = now;
			now = ++ver;
			if (old == -1)
			{
				mm[now] = make_pair(a, -1);
				continue;
			}
			mm[now] = make_pair(a, old);
		}
		if (str == "SAVE")
		{
			if (now == -1)
			{
				cout << -1 << ' ';
			}
			else
			{
				cout << mm[now].first << ' ';
			}
			save[a] = now;
		}
		if (str == "LOAD")
		{
			if (save.find(a) == save.end())
			{
				now = -1;
				cout << -1 << ' ';
				continue;
			}
			now = save[a];
			if (now == -1)
			{
				cout << -1 << ' ';
			}
			else
			{
				cout << mm[now].first << ' ';
			}
		}
	}
	return 0;
}
