#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<int> s;
	for (int i = 0; i < 5; ++i)
	{
		int a = 0;
		cin >> a;
		s.insert(a);
	}
	cout << s.size();
	return 0;
}
