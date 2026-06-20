#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<string, string>pss;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<pss>s;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string a, b;
		cin >> a >> b;
		pss p = make_pair(a, b);
		if (s.find(p) != s.end())
		{
			cout << "Yes";
			return 0;
		}
		s.insert(p);
	}
	cout << "No";
	return 0;
}
