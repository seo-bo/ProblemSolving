#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, sum = 0;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	int pivot = (sum + 1) / 2;
	for (int i = 1; i <= n; ++i)
	{
		if (pivot - v[i] > 0)
		{
			pivot -= v[i];
			continue;
		}
		cout << i << ' ' << pivot;
		return 0;
	}
	return 0;
}
