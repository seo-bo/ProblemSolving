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
	vector<int> ball(n + 1), pos(n + 1);
	iota(ball.begin(), ball.end(), 0);
	iota(pos.begin(), pos.end(), 0);
	while (q--)
	{
		int a = 0; // 공 번호
		cin >> a;
		int aidx = ball[a];
		int bidx = aidx - 1;
		if (aidx != n)
		{
			bidx = aidx + 1;
		}
		int b = pos[bidx];
		ball[a] = bidx, ball[b] = aidx;
		pos[aidx] = b, pos[bidx] = a;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << pos[i] << ' ';
	}
	return 0;
}
