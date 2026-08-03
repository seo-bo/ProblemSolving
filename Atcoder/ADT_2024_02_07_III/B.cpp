#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(10);
	for (auto& i : v)
	{
		cin >> i;
	}
	int x = 0;
	for (int i = 0; i < 3; ++i)
	{
		x = v[x];
	}
	cout << x;
	return 0;
}
