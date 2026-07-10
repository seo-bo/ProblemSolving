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
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	while (!v.empty())
	{
		cout << v.back() << '\n';
		v.pop_back();
	}
	return 0;
}
