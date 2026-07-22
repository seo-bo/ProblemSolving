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
	vector<int>v(n + 1);
	int pivot = 0, num = 0;
	while (m--)
	{
		int a = 0;
		cin >> a;
		if (++v[a] > pivot)
		{
			pivot = v[a], num = a;
		}
		else if (v[a] == pivot)
		{
			num = min(num, a);
		}
		cout << num << '\n';
	}
	return 0;
}
