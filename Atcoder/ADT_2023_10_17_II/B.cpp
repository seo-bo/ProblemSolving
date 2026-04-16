#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(8);
	for (auto& i : v)
	{
		cin >> i;
		if (i % 25 || i < 100 || i > 675)
		{
			cout << "No";
			return 0;
		}
	}
	vector<int>s = v;
	sort(s.begin(), s.end());
	cout << ((s == v) ? "Yes" : "No");
	return 0;
}
