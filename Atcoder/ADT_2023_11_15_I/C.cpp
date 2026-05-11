#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	int maxi = -1;
	vector<set<int>> s(101);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		maxi = max(a, maxi);
		s[a].insert(i);
	}
	for (int i = 0; i < k; ++i)
	{
		int a = 0;
		cin >> a;
		if (s[maxi].find(a) != s[maxi].end())
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
