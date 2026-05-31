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
	vector<int> v(m);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[j] += (str[j] == 'o');
		}
	}
	int cnt = 0, ans = 0;
	for (int i = 0; i < m; ++i)
	{
		if (v[i] == n)
		{
			cnt++;
		}
		else
		{
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	cout << max(ans, cnt);
	return 0;
}
