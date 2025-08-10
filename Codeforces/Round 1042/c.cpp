#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n >> k;
		map<pll, int>A;
		for (int i = 1; i <= n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			ll a = temp % k, b = llabs((temp % k) - k) % k;
			if (a > b)
			{
				swap(a, b);
			}
			A[make_pair(a, b)]++;
		}
		for (int i = 1; i <= n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			ll a = temp % k, b = llabs((temp % k) - k) % k;
			if (a > b)
			{
				swap(a, b);
			}
			A[make_pair(a, b)]--;
			if (A[make_pair(a, b)] == 0)
			{
				A.erase(make_pair(a, b));
			}
		}
		cout << ((A.empty()) ? "YES\n" : "NO\n");
	}
	return 0;
}
