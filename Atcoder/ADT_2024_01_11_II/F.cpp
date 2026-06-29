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
	vector<vector<int>>pos(n + 1);
	for (int i = 1; i <= 3 * n; ++i)
	{
		int a = 0;
		cin >> a;
		pos[a].push_back(i);
	}
	vector<pii>ans;
	for (int i = 1; i <= n; ++i)
	{
		int len = pos[i].size();
		ans.push_back(make_pair(pos[i][len / 2], i));
	}
	sort(ans.begin(), ans.end());
	for (auto& [a, b] : ans)
	{
		cout << b << ' ';
	}
	return 0;
}
