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
	vector<int>v;
	for (auto& i : str)
	{
		int p = i - '0';
		if (!p)
		{
			if (!v.empty() && v.back() == 0)
			{
				v.back() = 1;
				continue;
			}
		}
		v.push_back(p);
	}
	cout << v.size();
	return 0;
}
