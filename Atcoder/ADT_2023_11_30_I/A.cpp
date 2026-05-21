#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	--a, --b;
	for (auto &i : {-1, 1})
	{
		if ((a + i + 10) % 10 == b)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
