#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, vector<int>>mm;
	int n = 0;
	cin >> n;
	for (int i = 1; i <= 3 * n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a].push_back(i);
	}
	vector<pii>ans;
	for (auto& [a,b] : mm)
	{
		ans.push_back(make_pair(b[1], a));
	}
	sort(ans.begin(), ans.end());
	for (auto& [a, b] : ans)
	{
		cout << b << ' ';
	}
	return 0;
}
