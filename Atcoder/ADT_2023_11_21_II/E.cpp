#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<deque<int>> dq(m + 1);
	string str;
	cin >> str;
	vector<int> color(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> color[i];
		dq[color[i]].push_back(i);
	}
	for (auto &i : dq)
	{
		if (i.empty())
		{
			continue;
		}
		i.push_front(i.back());
		i.pop_back();
	}
	for (auto &i : color)
	{
		cout << str[dq[i].front()];
		dq[i].pop_front();
	}
	return 0;
}
