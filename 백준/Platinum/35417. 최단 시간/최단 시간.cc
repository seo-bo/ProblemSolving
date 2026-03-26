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
	for (int i = 1; i <= 2 * max(n, t); ++i)
	{
		if (!now.empty() && now.back().second + 1 == n)
		{
			cout << i;
			return 0;
		}
		vector<pii>A, B;
		int left = 0, right = 0;
		cin >> left >> right;
		for (auto& [a, b] : now)
		{
			a = max(1, a - 1), b = min(n, b + 1);
			if (A.empty() || A.back().second + 1 < a)
			{
				A.push_back(make_pair(a, b));
			}
			else
			{
				A.back().second = max(A.back().second, b);
			}
		}
		for (auto& [a, b] : A)
		{
			if (b < left || right < a)
			{
				B.push_back(make_pair(a, b));
				continue;
			}
			if (a < left)
			{
				B.push_back(make_pair(a, left - 1));
			}
			if (right < b)
			{
				B.push_back(make_pair(right + 1, b));
			}
		}
		if (B.empty())
		{
			break;
		}
		now = move(B);
	}
	cout << -1;
	return 0;
}