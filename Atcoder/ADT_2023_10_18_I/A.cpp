#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>a = { n / 16, n % 16 };
	for (auto& i : a)
	{
		if (i >= 10)
		{
			cout << char('A' + (i - 10));
		}
		else
		{
			cout << i;
		}
	}
	return 0;
}
