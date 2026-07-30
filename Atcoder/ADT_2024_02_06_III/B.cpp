#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int pre = 10;
	for (auto& i : str)
	{
		int a = i - '0';
		if (pre <= a)
		{
			cout << "No";
			return 0;
		}
		pre = a;
	}
	cout << "Yes";
	return 0;
}
