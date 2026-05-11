#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<string, string> pss;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pss> v(n);
	map<string, int> mm;
	for (auto &[a, b] : v)
	{
		cin >> a >> b;
		mm[a]++, mm[b]++;
	}
	for (auto &[a, b] : v)
	{
		--mm[a], --mm[b];
		if (mm[a] && mm[b])
		{
			cout << "No";
			return 0;
		}
		++mm[a], ++mm[b];
	}
	cout << "Yes";
	return 0;
}
