#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int pivot = INT_MIN, idx = -1;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		if (pivot <= v[i])
		{
			pivot = v[i];
			idx = i;
		}
	}
	cout << ((idx == 1) ? 0 : pivot + 1 - v[1]);
	return 0;
}
