#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0;
	cin >> n >> d;
	vector<ll>in, out, x;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		b = b - d + 1;
		if (a >= b)
		{
			continue;
		}
		in.push_back(a);
		out.push_back(b);
		x.push_back(a);
		x.push_back(b);
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	ll ans = 0, now = 0, idx = 0, jdx = 0, len = x.size(), ilen = in.size(), olen = out.size();
	for (int i = 0; i + 1 < len; ++i)
	{
		while (idx < ilen && in[idx] == x[i])
		{
			now++, idx++;
		}
		while (jdx < olen && out[jdx] == x[i])
		{
			now--, jdx++;
		}
		ll co = x[i + 1] - x[i];
		ans += co * now * (now - 1) / 2;
	}
	cout << ans;
	return 0;
}
