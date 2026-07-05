#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<set<int>>s(2 * (n + q));
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		s[i].insert(a);
	}
	vector<int>pos(n + 1);
	iota(pos.begin(), pos.end(), 0);
	int cnt = n + 1; // 쏟아붇고 비면 cnt 사용
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int aidx = pos[a], bidx = pos[b];
		if (s[aidx].empty())
		{
			cout << s[bidx].size() << '\n';
			continue;
		}
		if (s[aidx].size() > s[bidx].size())
		{
			for (auto& i : s[bidx])
			{
				s[aidx].insert(i);
			}
			cout << s[aidx].size() << '\n';
			pos[b] = aidx;
		}
		else
		{
			for (auto& i : s[aidx])
			{
				s[bidx].insert(i);
			}
			cout << s[bidx].size() << '\n';
		}
		pos[a] = cnt++;
	}
	return 0;
}
