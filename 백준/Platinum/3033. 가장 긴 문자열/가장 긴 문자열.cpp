#include <bits/stdc++.h>
#include <random>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	mt19937 engine((unsigned long long)time(NULL));
	uniform_int_distribution<ll>distribution((1LL << 25), (1LL << 30));
	auto check = bind(distribution, engine);
	ll base = check(), MOD = (1LL << 61) - 1;
	auto cal = [&](ll a, ll b)->ll
		{
			__int128 temp = (__int128)a * b;
			return ((ll)(temp & MOD) + (ll)(temp >> 61LL)) % MOD;
		};
	int n = 0;
	string str;
	cin >> n >> str;
	int len = str.size();
	vector<ll>H(len + 2), P(len + 2, 1);
	for (int i = 1; i <= len; ++i)
	{
		P[i] = cal(P[i - 1], base);
		__int128 temp = (__int128)H[i - 1] * base + (unsigned char)str[i - 1];
		H[i] = ((ll)(temp & MOD) + (ll)(temp >> 61LL)) % MOD;
	}
	auto sv = [&](int left, int right)
		{
			return (H[right] - cal(H[left - 1], P[right - left + 1]) + MOD) % MOD;
		};
	ll left = 1, right = len, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) >> 1;
		unordered_set<ll>ss;
		bool flag = false;
		for (int i = 1; i + mid - 1 <= len; ++i)
		{
			ll ok = sv(i, i + mid - 1);
			if (ss.find(ok) == ss.end())
			{
				ss.insert(ok);
				continue;
			}
			flag = true;
			break;
		}
		if (flag)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}