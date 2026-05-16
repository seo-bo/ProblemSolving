#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<int> s;
	int n = 0;
	cin >> n;
	for (int i = 1; i <= 2 * n + 1; ++i)
	{
		s.insert(i);
	}
	for (int f = 1;; f ^= 1)
	{
		if (f)
		{
			auto it = s.begin();
			cout << *it << endl;
			s.erase(it);
			continue;
		}
		int a = 0;
		cin >> a;
		if (!a)
		{
			return 0;
		}
		s.erase(a);
	}
	return 0;
}
