#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii> pos;
	vector<tp> v(n);
	for (auto &[a, b, c] : v)
	{
		cin >> a >> b >> c;
		pos.push_back(make_pair(a, b));
	}
	auto cal = [&](ll mid)
	{
		vector<vector<bool>> visited(n, vector<bool>(n));
		for (int i = 0; i < n; ++i)
		{
			queue<int> q;
			q.push(i);
			visited[i][i] = true;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				auto [x, y, co] = v[cur];
				for (int j = 0; j < n; ++j)
				{
					if (visited[i][j])
					{
						continue;
					}
					auto [nx, ny, _] = v[j];
					if ((__int128)mid * co >= llabs(x - nx) + llabs(y - ny))
					{
						visited[i][j] = true;
						q.push(j);
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			int flag = 1;
			for (int j = 0; j < n; ++j)
			{
				flag &= (visited[i][j]);
			}
			if (flag)
			{
				return true;
			}
		}
		return false;
	};
	ll left = 1, right = LLONG_MAX / 4, ans = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
