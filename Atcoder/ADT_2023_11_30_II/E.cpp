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
	vector<int> per(n + 1), pos(n + 1);
	iota(per.begin(), per.end(), 0);
	pos = per;
	while (q--)
	{
		int a = 0;
		cin >> a;
		int idx = pos[a], jdx = idx + 1;
		if (idx == n)
		{
			jdx = n - 1;
		}
		int b = per[jdx];
		pos[a] = jdx, pos[b] = idx;
		swap(per[idx], per[jdx]);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << per[i] << ' ';
	}
	return 0;
}
