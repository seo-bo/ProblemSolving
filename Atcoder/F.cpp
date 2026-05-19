#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> v(n + 1), a(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		a[i] = v[i];
	}
	sort(a.begin(), a.end());
	for (int i = 1; i <= k; ++i)
	{
		map<int, int> A;
		for (int j = i; j <= n; j += k)
		{
			if (++A[v[j]] == 0)
			{
				A.erase(v[j]);
			}
			if (--A[a[j]] == 0)
			{
				A.erase(a[j]);
			}
		}
		if (!A.empty())
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
