#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	int k = 0;
	cin >> str >> k;
	int len = str.size();
	reverse(str.begin(), str.end());
	vector<int> v(20);
	for (int i = 0; i < max(len, k); ++i)
	{
		if (i < len)
		{
			v[i] += (str[i] - '0');
		}
		int carry = v[i] / 10;
		if (i < k)
		{
			if (v[i] % 10 >= 5)
			{
				carry++;
			}
			v[i] = 0;
		}
		v[i] %= 10;
		v[i + 1] += carry;
	}
	ll ans = 0;
	for (int i = 19; i >= 0; --i)
	{
		ans = ans * 10 + v[i];
	}
	cout << ans;
	return 0;
}
