#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<int>BIT(MAX + 1);
	auto query = [&](int idx)
		{
			int res = 0;
			while (idx)
			{
				res += BIT[idx];
				idx -= idx & -idx;
			}
			return res;
		};
	auto update = [&](int idx, int delta)
		{
			while (idx <= MAX)
			{
				BIT[idx] += delta;
				idx += idx & -idx;
			}
		};
	vector<int>a = { 0 };
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
			a.push_back(v[i][j]);
		}
	}
	sort(a.begin(), a.end());
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			v[i][j] = lower_bound(a.begin(), a.end(), v[i][j]) - a.begin();
			update(v[i][j], 1);
		}
	}
	/* n = 5, m = 4 일때
	* 나올 수 있는 페어 - (1,2) (1,3) (1,4) (1,5) (2,3) (2,4) (2,5) (3,4) (3,5) (4,5) -> 10 -> 5 * 4 / 2
	* 한 수열 안에서 1 ~ m까지 정해지므로 그 합은 4 * 5 / 2 -> 10 (1 + 2 + 3 + 4)
	* 고로 일반화를 하면?
	* 나올 수 있는 페어 * 한 수열 안에서의 순서합 + (모든 원소에 대해)자기 보다 작은 원소 개수
	* n * (n-1) / 2 * m * (m+1) / 2 + sum[all_point] + lower_sum
	*/
	ll ans = n * (n - 1) / 2 * m * (m + 1) / 2;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			update(v[i][j], -1);
		}
		for (int j = 1; j <= m; ++j)
		{
			ans += query(v[i][j]);
		}
	}
	cout << ans;
	return 0;
}
