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
	vector<int>ans(n + 1);
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			ans[b]++;
		}
		else if (a == 2)
		{
			ans[b] += 2;
		}
		else
		{
			cout << ((ans[b] >= 2) ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}
