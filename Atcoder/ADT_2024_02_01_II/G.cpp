#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		ans++;
		if (!v.empty() && v.back().first == a)
		{
			if (v.back().first == a)
			{
				v.back().second++;
			}
		}
		else
		{
			v.push_back(make_pair(a, 1));
		}
		if (v.back().first == v.back().second)
		{
			ans -= v.back().first;
			v.pop_back();
		}
		cout << ans << '\n';
	}
	return 0;
}
