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
	vector<int>degree(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		degree[a]++, degree[b]++;
	}
	map<int, int>mm;
	for (int i = 1; i <= n; ++i)
	{
		mm[degree[i]]++;
	}
	if (mm.size() == 2 && mm[1] == n - 1 && mm[n - 1] == 1)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}
