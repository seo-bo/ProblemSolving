#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;
		cout << ((a == b) ? "OK" : "ERROR") << '\n';
	}
	return 0;
}