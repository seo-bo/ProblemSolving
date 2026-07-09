#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int muji = m, logo = 0;
	int nm = m, nl = 0;
	for (int i = 0; i < n; ++i)
	{
		char a;
		cin >> a;
		int p = a - '0';
		if (p == 0)
		{
			nm = muji, nl = logo;
		}
		else if (p == 1)
		{
			if (nm)
			{
				--nm;
			}
			else if (nl)
			{
				--nl;
			}
			else
			{
				logo++;
			}
		}
		else
		{
			if (nl)
			{
				--nl;
			}
			else
			{
				logo++;
			}
		}
	}
	cout << muji - m + logo;
	return 0;
}
