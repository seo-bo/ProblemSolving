#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string base = "atcoder";
	string str;
	cin >> str;
	int ans = 0;
	vector<int>cnt(8);
	for (auto& i : str)
	{
		int idx = 0;
		for (int j = 0; j < 7; ++j)
		{
			if (base[j] == i)
			{
				idx = j;
				break;
			}
		}
		for (int j = idx + 1; j < 7; ++j)
		{
			ans += cnt[j];
		}
		cnt[idx]++;
	}
	cout << ans;
	return 0;
}
