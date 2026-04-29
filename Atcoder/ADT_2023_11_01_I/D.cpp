#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<int, vector<pii>>mm;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int b = 0;
			cin >> b;
			mm[b].push_back(make_pair(a, i));
		}
	}
	int a = 0;
	cin >> a;
	sort(mm[a].begin(), mm[a].end());
	while (!mm[a].empty() && mm[a].front().first != mm[a].back().first)
	{
		mm[a].pop_back();
	}
	cout << mm[a].size() << '\n';
	for (auto& [a, b] : mm[a])
	{
		cout << b << ' ';
	}
	return 0;
}
