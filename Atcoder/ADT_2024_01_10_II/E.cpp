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
	map<int, vector<int>>left, right;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> b >> a;
	}
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		auto [x, y] = v[i];
		if (str[i] == 'R')
		{
			right[x].push_back(y);
		}
		else
		{
			left[x].push_back(y);
		}
	}
	for (auto& [a, b] : left)
	{
		sort(b.begin(), b.end());
	}
	for (auto& [a, b] : right)
	{
		sort(b.begin(), b.end());
	}
	for (auto& [a, b] : right)
	{
		for (auto& i : b)
		{
			if (left.find(a) != left.end() && upper_bound(left[a].begin(), left[a].end(), i) != left[a].end())
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
