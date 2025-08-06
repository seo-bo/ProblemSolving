#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll A = 0, B = 0, C = 0, D = 0, K = 0;
	cin >> A >> B >> C >> D >> K;
	if (!K)
	{
		ll pivot = (A + B - 1) / B;
		if (D > B && ((C + (D - B - 1)) / (D - B) < pivot))
		{
			cout << -1;
			return 0;
		}
		if ((A + C) <= pivot * D)
		{
			cout << -1;
		}
		else
		{
			cout << pivot;
		}
		return 0;
	}
	ll ans = 0;
	C += A;
	while (A)
	{
		if (B == 0)
		{
			cout << -1;
			return 0;
		}
		A = max(0LL, A - B);
		B = max(0LL, B - K);
		C = max(0LL, C - D);
		if (A >= C)
		{
			cout << -1;
			return 0;
		}
		ans++;
	}
	cout << ans;
	return 0;
}