#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
#define MAX 100001

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, l = 0;
	cin >> n >> l;
	vector<deque<pii>>dq(MAX * 2 + 5);
	dq[MAX].push_back(make_pair(0, 0));
	int ans = 0, p = MAX;
	for (int i = 1; i <= n; ++i)
	{
		char a;
		cin >> a;
		p += (a == 'K') ? 1 : -1;
		int co = INT_MAX;
		for (int j = p - 1; j <= p + 1; ++j)
		{
			while (!dq[j].empty() && dq[j].front().second < i - l)
			{
				dq[j].pop_front();
			}
			if (!dq[j].empty())
			{
				auto& [A, B] = dq[j].front();
				co = min(co, A + 1);
			}
		}
		while (!dq[p].empty() && dq[p].back().first >= co)
		{
			dq[p].pop_back();
		}
		dq[p].push_back(make_pair(co, i));
		ans = co;
	}
	cout << ans;
	return 0;
}