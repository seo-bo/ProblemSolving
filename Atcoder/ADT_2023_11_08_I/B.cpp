#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	for (int i = n - 1; i >= 0; --i)
	{
		cout << v[i] << '\n';
	}
	return 0;
}
