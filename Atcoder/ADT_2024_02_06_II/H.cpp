#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	string str, base, res(n, '#');
	cin >> str >> base;
	queue<int>q;
	for (int i = 0; i + m - 1 < n; ++i)
	{
		int flag = 1;
		for (int j = 0; j < m; ++j)
		{
			if (str[i + j] != base[j] || str[i + j] == '#')
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			for (int j = 0; j < m; ++j)
			{
				str[i + j] = '#';
				q.push(i + j);
			}
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int left = max(0, cur - m + 1), right = min(n - 1 - m + 1, cur);
		for (int i = left; i <= right; ++i)
		{
			int flag = 1;
			for (int j = 0; j < m; ++j)
			{
				if (str[i + j] == '#')
				{
					continue;
				}
				if (str[i + j] != base[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				for (int j = 0; j < m; ++j)
				{
					if (str[i + j] != '#')
					{
						q.push(i + j);
					}
					str[i + j] = '#';
				}
			}
		}
	}
	cout << ((str == res) ? "Yes" : "No");
	return 0;
}
