#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string base = "FMT";
	int n = 0;
	cin >> n;
	vector<int>v(3);
	for (auto& i : v)
	{
		cin >> i;
	}
	int idx = 0;
	while (1)
	{
		n -= v[idx];
		if (n < 0)
		{
			cout << base[idx];
			return 0;
		}
		idx = (idx + 1) % 3;
	}
	return 0;
}
