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
	vector<vector<int>>v(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			char a;
			cin >> a;
			int p = a - '0';
			v[i][j] = p;
		}
	}
	deque<int>res;
	for (int i = 1; i <= n; ++i)
	{
		res.push_back(v[1][i]);
	}
	for (int i = 2; i <= n - 1; ++i)
	{
		res.push_back(v[i][n]);
	}
	for (int i = n; i >= 1; --i)
	{
		res.push_back(v[n][i]);
	}
	for (int i = n - 1; i >= 2; --i)
	{
		res.push_back(v[i][1]);
	}
	res.push_front(res.back());
	res.pop_back();
	int idx = 0;
	for (int i = 1; i <= n; ++i)
	{
		v[1][i] = res[idx++];
	}
	for (int i = 2; i <= n - 1; ++i)
	{
		v[i][n] = res[idx++];
	}
	for (int i = n; i >= 1; --i)
	{
		v[n][i] = res[idx++];
	}
	for (int i = n - 1; i >= 2; --i)
	{
		v[i][1] = res[idx++];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}
