#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, string>ss;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<ss, int>ss;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string a, b;
		cin >> a >> b;
		if (++ss[make_pair(a, b)] == 2)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
