#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void) // 매칭 안하는 경우의 수도 고려해야함
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int len = max(n, m);
	vector<ll>fact(len + 1, 1);
	for (ll i = 2; i <= len; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	vector<ll>A(n), B(m);
	for (auto& i : A)
	{
		cin >> i;
	}
	sort(A.begin(), A.end());
	for (auto& i : B)
	{
		cin >> i;
	}
	sort(B.rbegin(), B.rend());
	ll mini = LLONG_MAX;
	for (int i = 0; i < n; ++i)
	{
		ll pivot = A[i];
		if (i < m)
		{
			pivot += B[i];
		}
		mini = min(mini, pivot);
	}
	ll ans = 0;
	auto it = lower_bound(A.begin(), A.end(), mini) - A.begin();
	sort(B.begin(), B.end());
	ll per = n - it, nokori = m - it; // 자유 학생, 자유 멘토
	auto sv = [&](ll a, ll b)
		{
			auto power = [&](ll base)
				{
					ll res = 1, exp = MOD - 2;
					while (exp)
					{
						if (exp & 1)
						{
							res = (res * base) % MOD;
						}
						base = (base * base) % MOD;
						exp >>= 1;
					}
					return res;
				};
			return fact[a] * power(fact[b]) % MOD * power(fact[a - b]) % MOD;
		};
	ll temp = 1; // 무조건 매칭
	for (int i = 0; i < it; ++i)
	{
		auto jt = m - (lower_bound(B.begin(), B.end(), mini - A[i]) - B.begin());
		temp = (temp * (jt - i)) % MOD;
	}
	for (int i = 0; i <= min(per, nokori); ++i) // 학생 i명, 멘토 i명 고르고 매칭
	{
		ans = (ans + sv(per, i) * sv(nokori, i) % MOD * fact[i] % MOD) % MOD;
	}
	cout << ans * temp % MOD;
	return 0;
}