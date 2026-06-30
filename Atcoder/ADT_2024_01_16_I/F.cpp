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
	set<int>s;
	for (int i = 1; i <= 2 * n + 1; ++i)
	{
		s.insert(i);
	}
	while (1)
	{
		int p = *s.begin();
		cout << p << endl;
		s.erase(p);
		cin >> p;
		if (!p)
		{
			return 0;
		}
		s.erase(p);
	}
	return 0;
}
