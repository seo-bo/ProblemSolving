#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>> v(n, vector<int>(27));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (auto &j : str)
		{
			v[i][j - 'a']++;
		}
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); ++i)
	{
		int temp = 0;
		vector<int> alpha(27);
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				for (int z = 0; z < 26; ++z)
				{
					alpha[z] += v[j][z];
				}
			}
		}
		for (int j = 0; j < 26; ++j)
		{
			if (!alpha[j])
			{
				continue;
			}
			temp += (alpha[j] == k);
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}
