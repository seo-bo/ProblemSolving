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
	int pivot = INT_MAX, idx = -1;
	vector<string>v(n);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> v[i] >> a;
		if (pivot > a)
		{
			pivot = a;
			idx = i;
		}
	}
	int x = idx;
	do
	{
		cout << v[x] << '\n';
		x = (x + 1) % n;
	} while (x != idx);
	return 0;
}
