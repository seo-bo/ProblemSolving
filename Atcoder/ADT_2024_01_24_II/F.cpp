#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MAX 1000000

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>suffix(MAX + 10), v(n + 1), cnt(MAX + 10);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		cnt[v[i]]++;
	}
	for (int i = MAX; i >= 0; --i)
	{
		suffix[i] = suffix[i + 1] + cnt[i] * i;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << suffix[v[i]] - cnt[v[i]] * v[i] << ' ';
	}
	return 0;
}
