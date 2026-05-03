#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Matrix
{
	ll cost[2][2];
	Matrix(ll x)
	{
		cost[0][0] = cost[1][0] = 0;
		cost[0][1] = x, cost[1][1] = LLONG_MIN / 8;
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, k = 0;
		cin >> n >> k;
		vector<ll>v(n + 1), prefix(n + 1);
		ll mini = LLONG_MAX, two = LLONG_MAX;
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
			mini = min(mini, v[i]);
			if (i >= 2)
			{
				two = min(two, v[i] + v[i - 1]);
			}
			prefix[i] = prefix[i - 1] + v[i];
		}
		if (k == 1)
		{
			cout << mini << '\n';
			continue;
		}
		auto merge = [&](Matrix a, Matrix b)
			{
				Matrix nxt(0);
				for (int i = 0; i < 2; ++i)
				{
					for (int j = 0; j < 2; ++j)
					{
						nxt.cost[i][j] = max(a.cost[i][0] + b.cost[0][j], a.cost[i][1] + b.cost[1][j]);
					}
				}
				return nxt;
			};
		auto sv = [&](int len)
			{
				if (len > n)
				{
					return LLONG_MAX;
				}
				vector<Matrix>A = { Matrix(v[len - 1]) }, B;
				auto cal = [&](int left, int right)
					{
						ll base = prefix[right] - prefix[left - 1];
						if (A.empty())
						{
							return base - max(B.back().cost[0][0], B.back().cost[0][1]);
						}
						if (B.empty())
						{
							return base - max(A.back().cost[0][0], A.back().cost[0][1]);
						}
						Matrix now = merge(A.back(), B.back());
						return base - max(now.cost[0][0], now.cost[0][1]);
					};
				for (int i = len - 2; i >= 2; --i)
				{
					A.push_back(merge(Matrix(v[i]), A.back()));
				}
				ll res = LLONG_MAX;
				res = min(res, cal(1, len));
				for (int left = 1, right = len + 1; right <= n; ++right)
				{
					if (A.empty())
					{
						B.clear();
						A.push_back(Matrix(v[right - 2]));
						for (int i = right - 3; i >= left + 1; --i)
						{
							A.push_back(merge(Matrix(v[i]), A.back()));
						}
					}
					A.pop_back();
					left++;
					if (B.empty())
					{
						B.push_back(Matrix(v[right - 1]));
					}
					else
					{
						B.push_back(merge(B.back(), Matrix(v[right - 1])));
					}
					res = min(res, cal(left, right));
				}
				return res;
			};
		cout << min((k == 2) ? two : sv(k), sv(k + 1)) << '\n';
	}
	return 0;
}
