#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string a, b;
	for (int i = 0; i < 3; ++i)
	{
		char p;
		cin >> p;
		a += p;
	}
	for (int i = 0; i < 3; ++i)
	{
		char p;
		cin >> p;
		b += p;
	}
	a = a + a;
	cout << ((a.find(b) != string::npos) ? "Yes" : "No");
	return 0;
}
