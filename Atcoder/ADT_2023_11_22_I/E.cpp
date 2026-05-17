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
	vector<int> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}
	int cnt = 0;
	do
	{
		if (cnt++ == 1)
		{
			break;
		}
	} while (prev_permutation(v.begin(), v.end()));
	for (auto &i : v)
	{
		cout << i << ' ';
	}
	return 0;
}
