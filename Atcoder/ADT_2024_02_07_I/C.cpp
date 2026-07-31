#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0;
	cin >> n >> d;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int ans = 0, now = 0;
	for (int i = 0; i < d; ++i)
	{
		int flag = 1;
		for (int j = 0; j < n; ++j)
		{
			flag &= (v[j][i] == 'o');
		}
		if (!flag)
		{
			ans = max(ans, now);
			now = 0;
		}
		else
		{
			now++;
		}
	}
	cout << max(ans, now);
	return 0;
}
