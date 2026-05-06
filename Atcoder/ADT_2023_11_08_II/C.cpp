#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(2001);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v[a]++;
	}
	for (int i = 0; i <= 2000; ++i)
	{
		if (!v[i])
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
