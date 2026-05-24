#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, string> psi;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string> v(n);
	int pivot = INT_MAX, idx = -1;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> v[i] >> a;
		if (a < pivot)
		{
			pivot = a, idx = i;
		}
	}
	for (int i = idx; i < n; ++i)
	{
		cout << v[i] << '\n';
	}
	for (int i = 0; i < idx; ++i)
	{
		cout << v[i] << '\n';
	}
	return 0;
}
