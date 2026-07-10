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
	int ban = 2 * n;
	string str;
	cin >> str;
	vector<vector<int>>v(2 * n + 1, vector<int>(2, ban));
	for (int i = 1; i <= n; ++i)
	{
		char p = str[i - 1];
		int pre = 0, nxt = 0;
		if (p == 'L')
		{
			pre = v[i - 1][0], nxt = i - 1;
		}
		else
		{
			pre = i - 1, nxt = v[i - 1][1];
		}
		v[i][0] = pre, v[i][1] = nxt;
		v[pre][1] = i, v[nxt][0] = i;
	}
	int x = ban;
	for (int i = 0; i <= n; ++i)
	{
		if (v[i][0] == ban)
		{
			x = i;
			break;
		}
	}
	while (x != ban)
	{
		cout << x << ' ';
		x = v[x][1];
	}
	return 0;
}
