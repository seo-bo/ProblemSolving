#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll>pll;
typedef tuple<ll, ld, ld>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<tp>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0;
		ld c = 0, d = 0;
		cin >> a >> b >> c >> d;
		graph[a].push_back(make_tuple(b, c, d));
	}
	ld left = 0, right = INT_MAX, ans = -1;
	/*
	* 특정 비율 mid를 달성 가능한가?
	* 그랬을때 b, c가 있으면
	* b / c >= mid여야함
	* 이는 b >= mid * c -> b - mid * c >= 0로 변환이 됨
	* 이때 b는 임의의 집합 S = {??}에 있는 원소에 대해 sum(co1_Si)가 되고, c도 sum(co2_Si)가 된다면?
	* 간선을 b - mid * c로 변환시킬 수 있지 않나?
	*/
	auto cal = [&](ld mid)
		{
			vector<ld>dp(n + 1, INT_MIN);
			dp[1] = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (dp[i] == INT_MIN)
				{
					continue;
				}
				for (auto& [nv, co1, co2] : graph[i])
				{
					dp[nv] = max(dp[nv], dp[i] + co1 - mid * co2);
				}
			}
			return (dp[n] >= 0);
		};
	for (int i = 1; i <= 100; ++i)
	{
		ld mid = (left + right) / 2;
		if (cal(mid))
		{
			left = ans = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
