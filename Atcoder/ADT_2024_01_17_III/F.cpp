#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<pii>>color(k + 1);
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		int p = str[i] - 'a';
		color[a].push_back(make_pair(i, p));
	}
	vector<pii>ans;
	for (int i = 1; i <= k; ++i)
	{
		int len = color[i].size();
		for (int j = len - 1; j >= 0; --j)
		{
			int nxt = color[i][(j + 1) % len].first;
			ans.push_back(make_pair(nxt, color[i][j].second));
		}
	}
	sort(ans.begin(), ans.end());
	for (auto& [_, a] : ans)
	{
		cout << char(a + 'a');
	}
	return 0;
}
