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
	string str;
	cin >> str;
	int a = 0, b = 0;
	for (auto& i : str)
	{
		if (i == '|')
		{
			a += (a == 0 || b == 1);
		}
		else if (i == '*')
		{
			b += (a == 1);
		}
	}
	cout << ((a == 2 && b == 1) ? "in" : "out");
	return 0;
}
