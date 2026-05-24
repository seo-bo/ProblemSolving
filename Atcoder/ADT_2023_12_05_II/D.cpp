#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<string> A;
	int n = 0, m = 0;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		string str, temp;
		cin >> str;
		for (int i = 3; i < 6; ++i)
		{
			temp += str[i];
		}
		v[i] = temp;
	}
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		A.insert(str);
	}
	int ans = 0;
	for (auto &i : v)
	{
		ans += (A.find(i) != A.end());
	}
	cout << ans;
	return 0;
}
