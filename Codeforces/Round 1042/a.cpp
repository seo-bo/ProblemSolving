#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		int ans = 1;
		for (int i = 1; i <= n; ++i)
		{
			int temp = 0;
			cin >> temp;
			if (v[i] > temp)
			{
				ans += v[i] - temp;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
