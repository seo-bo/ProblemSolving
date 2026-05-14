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
	string str;
	cin >> str;
	for (auto &i : str)
	{
		if (i == 'o')
		{
			if (k)
			{
				k--;
				cout << 'o';
			}
			else
			{
				cout << 'x';
			}
			continue;
		}
		cout << 'x';
	}
	return 0;
}
