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
	string str;
	cin >> str;
	auto cal = [&]
		{
			int ans = 0, now = 0, flag = 0;
			for (auto& i : str)
			{
				if (i == '-')
				{
					flag = 1;
					ans = max(ans, now);
					now = 0;
					continue;
				}
				if (flag)
				{
					now++;
				}
			}
			return max(ans, now);
		};
	int ans = cal();
	reverse(str.begin(), str.end());
	ans = max(ans, cal());
	cout << ((ans) ? ans : -1);
	return 0;
}
