#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n), s;
	for (auto& i : v)
	{
		cin >> i;
		s.push_back(i);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	map<int, int>mm;
	for (auto& i : v)
	{
		int idx = upper_bound(s.begin(), s.end(), i) - s.begin();
		mm[s.size() - idx]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << mm[i - 1] << '\n';
	}
	return 0;
}
