#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, lim = INT_MAX;
	cin >> n >> m;
	vector<vector<int>> v(m + 1);
	priority_queue<int, vector<int>, greater<int>> A;
	priority_queue<int> B;
	vector<int> p;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		lim = min(lim, b);
		p.push_back(a);
		v[a].push_back(b);
		B.push(a);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	for (auto &i : p)
	{
		A.push(i);
	}
	vector<ll> ans(m + 1);
	for (int i = 1; i <= lim; ++i)
	{
		int right = B.top();
		int len = right - i + 1;
		ans[len]++, ans[m - i + 2]--;
		while (!A.empty() && A.top() <= i)
		{
			for (auto &j : v[A.top()])
			{
				B.push(j);
			}
			A.pop();
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		ans[i] += ans[i - 1];
		cout << ans[i] << ' ';
	}
	return 0;
}
