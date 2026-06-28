#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int a = 0, b = 0;
	for (auto& i : str)
	{
		a += (i == 'E');
		b += (i == 'W');
	}
	cout << ((a > b) ? "East" : "West");
	return 0;
}
