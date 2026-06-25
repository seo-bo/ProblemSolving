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
	map<string, int>mm;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		mm[str]++;
	}
	int pivot = INT_MIN;
	string ans;
	for (auto& [a, b] : mm)
	{
		if (b > pivot)
		{
			pivot = b;
			ans = a;
		}
	}
	cout << ans;
	return 0;
}
