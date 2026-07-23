#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>pos(n);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		pos[a] = i;
	}
	int base = n / 2;
	vector<ll>prefix(n + 10);
	ll now = 0;
	auto cal = [&](int left, int right, int p)
		{
			left = (left % n + n) % n, right = (right % n + n) % n;
			prefix[left] += p, prefix[right + 1] -= p;
			if (left > right)
			{
				prefix[n] -= p, prefix[0] += p;
			}
		};
	for (int i = 0; i < n; ++i)
	{
		int nxt = pos[i], turn = 0;
		if (nxt < i)
		{
			turn = n - i + nxt;
		}
		else
		{
			turn = nxt - i;
		}
		now += min(turn, n - turn);
		/*
		* 패널티가 증가하려면 -turn <= o <= base - 1 - turn
		* 패널티가 감소하려면 base - turn <= o <= n - 1 - turn (홀수 짝수 체크)
		*/
		cal(-turn, base - 1 - turn, 1);
		cal(base - turn + n % 2, n - 1 - turn, -1);
	}
	now += prefix[0];
	ll ans = now;
	for (int i = 1; i < n; ++i)
	{
		prefix[i] += prefix[i - 1];
		now += prefix[i];
		ans = min(ans, now);
	}
	cout << ans;
	return 0;
}
