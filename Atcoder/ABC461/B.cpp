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
	vector<int>A(n + 1), B(n + 1);
	for (int i = 1; i<=n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i<=n; ++i)
	{
		cin >> B[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (B[A[i]] == i)
		{
			continue;
		}
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}
