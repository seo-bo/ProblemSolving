#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	vector<ll> prefix(len + 1);
	for (int i = 1; i <= len; ++i)
	{
		prefix[i] = prefix[i - 1] + str[i - 1] - '0';
	}
	vector<ll> res;
	ll carry = 0;
	for (int i = len; i >= 1; --i)
	{
		ll co = carry + prefix[i];
		res.push_back(co % 10);
		carry = co / 10;
	}
	while(carry)
	{
		res.push_back(carry % 10);
		carry /= 10;
	}
	reverse(res.begin(), res.end());
	for (auto &i : res)
	{
		cout << i;
	}
	return 0;
}
