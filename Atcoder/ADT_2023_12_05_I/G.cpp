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
	int left = 1, right = n;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		cout << format("? {}", mid) << endl;
		int p = 0;
		cin >> p;
		if (p == 0)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
		if (left + 1 == right)
		{
			cout << format("! {}", left) << endl;
			return 0;
		}
	}
	return 0;
}
