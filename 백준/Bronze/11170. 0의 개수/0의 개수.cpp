#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0, ans = 0;
		cin >> a >> b;
		for (int i = a; i <= b; ++i)
		{
			string str = to_string(i);
			for (auto& j : str)
			{
				if (j == '0')
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}