#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<pii> s;
	int n = 0, q = 0;
	cin >> n >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			s.insert(make_pair(b, c));
		}
		else if (a == 2)
		{
			s.erase(make_pair(b, c));
		}
		else
		{
			if (s.find(make_pair(b, c)) != s.end() && s.find(make_pair(c, b)) != s.end())
			{
				cout << "Yes\n";
				continue;
			}
			cout << "No\n";
		}
	}
	return 0;
}
