#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a]++;
	}
	for (auto it = mm.rbegin(); it != mm.rend(); ++it)
	{
		cout << it->second << '\n';
	}
	for (int i = 0; i < n - mm.size(); ++i)
	{
		cout << 0 << '\n';
	}
	return 0;
}
