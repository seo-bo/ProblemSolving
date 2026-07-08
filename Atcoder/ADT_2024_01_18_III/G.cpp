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
	vector<int> temp(10);
	int len = str.size();
	map<vector<int>, int> mm;
	mm[temp] = 1;
	ll ans = 0;
	for (int i = 0; i < len; ++i)
	{
		int p = str[i] - '0';
		temp[p] = (temp[p] + 1) % 2;
		ans += mm[temp];
		mm[temp]++;
	}
	cout << ans;
	return 0;
}
