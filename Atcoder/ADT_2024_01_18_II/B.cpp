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
	int pre = 0;
	cin >> pre;
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0;
		cin >> a;
		if (a != pre)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
