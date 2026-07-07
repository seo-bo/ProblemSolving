#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	vector<int>v;
	for (int i = 1; i < n; ++i)
	{
		if (str[i - 1] == str[i])
		{
			v.push_back(i);
		}
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int it = lower_bound(v.begin(), v.end(), a) - v.begin();
		int jt = upper_bound(v.begin(), v.end(), b - 1) - v.begin();
		cout << max(0, jt - it) << '\n';
	}
	return 0;
}
