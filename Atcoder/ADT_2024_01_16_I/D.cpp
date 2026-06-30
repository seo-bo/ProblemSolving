#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int ans = 0, n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int p = 0, flag = 1;
		cin >> p;
		string str = to_string(i);
		char pivot = str.front();
		for (auto& j : str)
		{
			if (j != pivot)
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
		{
			continue;
		}
		int a = i % 10, temp = a;
		while (temp <= p)
		{
			ans++;
			temp = temp * 10 + a;
		}
	}
	cout << ans;
	return 0;
}
