#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii>v;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			char a;
			cin >> a;
			if (a == '.')
			{
				continue;
			}
			v.push_back(make_pair(i, j));
		}
	}
	int len = v.size(), ans = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			for (int k = j + 1; k < len; ++k)
			{
				for (int z = k + 1; z < len; ++z)
				{
					map<int, int>mm;
					for (auto& [a, b] : { v[i],v[j],v[k],v[z] })
					{
						for (auto& [c, d] : { v[i],v[j],v[k],v[z] })
						{
							int p = (a - c) * (a - c) + (b - d) * (b - d);
							if (!p)
							{
								continue;
							}
							mm[p]++;
						}
					}
					if (mm.size() != 2)
					{
						continue;
					}
					auto it = mm.begin();
					if (it->second == 8 && next(it)->second == 4)
					{
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
