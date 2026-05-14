#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string base = "FMT";
	int x = 0;
	cin >> x;
	vector<int> v(3);
	for (auto &i : v)
	{
		cin >> i;
	}
	int idx = 0;
	while (1)
	{
		if (x < v[idx])
		{
			cout << base[idx];
			return 0;
		}
		x -= v[idx];
		idx = (idx + 1) % 3;
	}
	return 0;
}
