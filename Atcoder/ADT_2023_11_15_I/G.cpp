#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<bool> prime(301, 1);
	for (int i = 2; i <= 300; ++i)
	{
		for (int j = i * i; j <= 300; j += i)
		{
			prime[j] = 0;
		}
	}
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	for (int i = a; i <= b; ++i)
	{
		int flag = 0;
		for (int j = c; j <= d; ++j)
		{
			flag |= prime[i + j];
		}
		if (!flag)
		{
			cout << "Takahashi";
			return 0;
		}
	}
	cout << "Aoki";
	return 0;
}
