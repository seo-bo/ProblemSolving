#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int now = 0, len = v.size();
	for (int i = 0; i < min(m, len); ++i)
	{
		if (now == v[i])
		{
			now++;
			continue;
		}
		break;
	}
	cout << now;
	return 0;
}
