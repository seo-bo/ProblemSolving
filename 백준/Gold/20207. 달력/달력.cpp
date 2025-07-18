#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 아니 bfs를 하면 연속된 일정을 못보잖아;
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(401, 0);
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a]++;
		v[b + 1]--;
	}
	vector<int>prefix(401, 0);
	for (int i = 1; i <= 400; ++i)
	{
		prefix[i] = prefix[i - 1] + v[i];
	}
	int ans = 0, x = 0, y = 0;
	for (int i = 1; i <= 400; ++i)
	{
		if (!prefix[i])
		{
			ans += (i - x) * y;
			x = y = 0;
			continue;
		}
		else
		{
			y = max(y, prefix[i]);
		}
		if (!x)
		{
			x = i;
		}
	}
	cout << ans;
	return 0;
}