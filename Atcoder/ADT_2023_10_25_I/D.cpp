#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>degree(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		degree[a]++, degree[b]++;
	}
	int a = 0, b = 0;
	for (int i = 1; i <= n; ++i)
	{
		a += (degree[i] == 1), b += (degree[i] != 1);
	}
	if (a == n - 1 && b == 1)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}
