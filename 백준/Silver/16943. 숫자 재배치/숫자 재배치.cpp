#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	string str = to_string(a);
	ll ans = -1;
	sort(str.begin(), str.end());
	do
	{
		if (str.front() == '0')
		{
			continue;
		}
		ll pivot = stoll(str);
		if (pivot < b)
		{
			ans = max(ans, pivot);
		}
	} while (next_permutation(str.begin(), str.end()));
	cout << ans;
	return 0;
}