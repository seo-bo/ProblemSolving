#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll op(ll a, ll b)
{
	return gcd(a, b);
}

ll e()
{
	return 0;
}

// gcd(x,y) = gcd(x, y-x)?

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	segtree<ll, op, e>row(n + 3), col(n + 3);
	vector<ll>A(n + 1), B(n + 1);
	// 왼-> 오른쪽으로 인접 빼주기
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
		row.set(i, A[i] - A[i - 1]);
	}
	// 위 -> 아래로 인접 빼주기. 이러면 | 와 ㅡ 방향 말고는 전부 0이되는뎅 gcd(0,?) = ? 이니까 ㄱㅊ
	for (int i = 1; i <= n; ++i)
	{
		cin >> B[i];
		col.set(i, B[i] - B[i - 1]);
	}
	while (q--)
	{
		int h1 = 0, h2 = 0, w1 = 0, w2 = 0;
		cin >> h1 >> h2 >> w1 >> w2;
		ll ans = gcd(row.prod(h1 + 1, h2 + 1), col.prod(w1 + 1, w2 + 1));
		cout << gcd(A[h1] + B[w1], ans) << '\n';
	}
	return 0;
}
