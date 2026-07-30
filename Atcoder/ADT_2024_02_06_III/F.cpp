#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef tuple<ll, ll, ll>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<tp>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b, c] = v[i];
		cin >> a >> b;
		c = i;
	}
	sort(v.begin() + 1, v.end(), [&](tp& a, tp& b)
		{
			auto [aa, ab, ac] = a;
			auto [ba, bb, bc] = b;
			ll A = aa * (ba + bb), B = ba * (aa + ab);
			if (A == B)
			{
				return ac < bc;
			}
			return A > B;
		});
	for (int i = 1; i <= n; ++i)
	{
		cout << get<2>(v[i]) << ' ';
	}
	return 0;
}
