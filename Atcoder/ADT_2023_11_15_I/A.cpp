#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0;
	cin >> a;
	for (auto &i : {40, 70, 90})
	{
		if (a < i)
		{
			cout << i - a;
			return 0;
		}
	}
	cout << "expert";
	return 0;
}
