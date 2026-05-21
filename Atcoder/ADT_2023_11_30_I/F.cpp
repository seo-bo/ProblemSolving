#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, A = 0, B = 0;
	cin >> n >> A >> B;
	string str;
	cin >> str;
	deque<char> dq;
	for (auto &i : str)
	{
		dq.push_back(i);
	}
	ll ans = LLONG_MAX;
	int len = str.size();
	for (int i = 0; i <= n; ++i)
	{
		ll temp = A * i;
		for (int j = 0; j < len / 2; ++j)
		{
			temp += (dq[j] != dq[len - j - 1]) * B;
		}
		ans = min(ans, temp);
		dq.push_back(dq.front());
		dq.pop_front();
	}
	cout << ans;
	return 0;
}
