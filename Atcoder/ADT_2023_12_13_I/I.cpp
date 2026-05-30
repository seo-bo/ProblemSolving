#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0, lim = 2 * 1e6;
	cin >> n >> q;
	vector<int> box(lim + 5), rev(lim + 5);
	for (int i = 1; i <= n; ++i)
	{
		box[i] = rev[i] = i;
	}
	dsu p(lim + 5);
	int cnt = n, ver = lim / 2 + 1;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			p.merge(box[b], box[c]);
			int nxt = p.leader(box[b]);
			box[b] = nxt, rev[nxt] = b;
			box[c] = ver, rev[ver] = c;
			ver++;
		}
		else if (a == 2)
		{
			p.merge(box[b], ++cnt);
			int nxt = p.leader(box[b]);
			box[b] = nxt, rev[nxt] = b;
		}
		else
		{
			cout << rev[p.leader(b)] << '\n';
		}
	}
	return 0;
}
