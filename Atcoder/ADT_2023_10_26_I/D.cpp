#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>rev(n + 1);
	int cnt = 1;
	for (int i = 1; i <= m; ++i)
	{
		int a = 0;
		cin >> a;
		if (!rev[a])
		{
			rev[a] = cnt++;
		}
		rev[a + 1] = rev[a];
	}
	int idx = 1;
	while (idx <= n)
	{
		if (!rev[idx])
		{
			cout << idx++ << ' ';
			continue;
		}
		int pivot = rev[idx], start = idx, end = -1;
		while (idx <= n && rev[idx] == pivot)
		{
			idx++;
		}
		end = idx - 1;
		for (int i = end; i >= start; --i)
		{
			cout << i << ' ';
		}
	}
	return 0;
}
