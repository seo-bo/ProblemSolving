#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int> mm;
	for (int i = 0; i < 5; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a]++;
	}
	auto it = mm.begin();
	if (mm.size() != 2)
	{
		cout << "No";
		return 0;
	}
	cout << ((it->second == 2 || it->second == 3) ? "Yes" : "No");
	return 0;
}
