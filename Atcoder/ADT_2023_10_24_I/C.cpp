#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v = { 0,3,1,4,1,5,9 };
	char a, b;
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	int ans = 0;
	for (int i = a - 'A' + 1; i <= b - 'A'; ++i)
	{
		ans += v[i];
	}
	cout << ans;
	return 0;
}
