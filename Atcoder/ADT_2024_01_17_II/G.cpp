#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	set<int>no, ok;
	for (int i = 1; i <= n; ++i)
	{
		no.insert(i);
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a;
		if (a == 2)
		{
			cin >> b;
			ok.erase(b);
		}
		else if (a == 1)
		{
			int p = *no.begin();
			no.erase(p), ok.insert(p);
		}
		else
		{
			int p = *ok.begin();
			cout << p << '\n';
		}
	}
	return 0;
}
