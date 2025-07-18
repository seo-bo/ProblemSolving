#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	while (1)
	{
		map<ll, vector<pll>>ok;
		for (ll tt = 2; tt <= n - 1; ++tt)
		{
			cout << format("{} {}", tt, tt) << endl;
			ll temp = 0;
			cin >> temp;
			if (temp == -1)
			{
				return 0;
			}
			ok[temp].push_back(make_pair(tt, tt));
		}
		vector<pll>pivot;
		for (auto& [a, b] : ok)
		{
			if (b.size() > 1)
			{
				int len = b.size();
				bool check = true;
				int x = b[0].first, y = b[len - 1].second;
				for (int i = 0; i < len - 1; ++i)
				{
					auto [c, d] = b[i];
					if (llabs(b[i].first - b[i + 1].first) != 1)
					{
						check = false;
						break;
					}
				}
				if (check)
				{
					int temp = 0;
					cout << format("{} {}", x, y) << endl;
					cin >> temp;
					if (temp == -1)
					{
						return 0;
					}
					cout << format("{} {}", y, x) << endl;
					cin >> temp;
					return 0;
				}
			}
		}
	}
	return 0;
}