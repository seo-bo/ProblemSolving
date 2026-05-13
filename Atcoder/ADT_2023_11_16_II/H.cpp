#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

/*
[1 2]
2 3 1 4 5 

[4 3]
1 3 4 2 5 

[1 2 3 4]
2 4 3 1 5
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> v(m + 3);
	for (int i = 1; i <= m; ++i)
	{
		cin >> v[i];
	}
	vector<int> suffix(n + 1);
	iota(suffix.begin(), suffix.end(), 0);
	for (int i = m; i >= 2; --i)
	{
		int p = v[i];
		swap(suffix[p], suffix[p + 1]);
	}
	int now = 1;
	for (int i = 1; i <= m; ++i)
	{
		cout << suffix[now] << '\n';
		int p = v[i];
		if (now == p)
		{
			now = p + 1;
		}
		else if (now == p + 1)
		{
			now = p;
		}
		swap(suffix[v[i + 1]], suffix[v[i + 1] + 1]);
	}
	return 0;
}
