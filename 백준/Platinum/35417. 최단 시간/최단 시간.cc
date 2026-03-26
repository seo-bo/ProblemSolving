#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, t = 0;
	cin >> n >> t;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	vector<pii>now = { make_pair(1,1) };
	for (int i = 1; i <= t; ++i)
	{
		if (!now.empty() && now.back().second + 1 == n)
		{
			cout << i;
			return 0;
		}
		vector<pii>temp;
		auto cal = [&](int a, int b)
			{
				if (a > b)
				{
					return;
				}
				if (temp.empty() || temp.back().second + 1 < a)
				{
					temp.push_back(make_pair(a, b));
				}
				else
				{
					temp.back().second = max(temp.back().second, b);
				}
			};
		int left = 0, right = 0;
		cin >> left >> right;
		for (auto& [a, b] : now)
		{
			a = max(1, a - 1), b = min(n, b + 1);
			if (left > b || right < a)
			{
				cal(a, b);
				continue;
			}
			cal(a, left - 1), cal(right + 1, b);
		}
		if (temp.empty())
		{
			cout << -1;
			return 0;
		}
		now = move(temp);
	}
	cout << t + (n - now.back().second);
	return 0;
}