#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii>pos;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			char a;
			cin >> a;
			if (a == '#')
			{
				pos.push_back(make_pair(i, j));
			}
		}
	}
	int len = pos.size(), ans = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			for (int k = j + 1; k < len; ++k)
			{
				for (int z = k + 1; z < len; ++z)
				{
					vector<pii>temp = { pos[i],pos[j],pos[k],pos[z] };
					sort(temp.begin(), temp.end());
					map<int, int>mm;
					for (auto& [x, y] : temp)
					{
						for (auto& [nx, ny] : temp)
						{
							int co = (nx - x) * (nx - x) + (ny - y) * (ny - y);
							if (co)
							{
								mm[co]++;
							}
						}
					}
					auto it = mm.begin();
					ans += (mm.size() == 2 && it->second == 8 && next(it)->second == 4);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
