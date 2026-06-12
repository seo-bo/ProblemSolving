#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto cal = [&]
		{
			string str, temp;
			cin >> str;
			int cnt = 0;
			for (auto& i : str)
			{
				if (i == '@')
				{
					cnt++;
					continue;
				}
				temp += i;
			}
			return make_pair(cnt, temp);
		};
	string base = "atcoder";
	auto [a, A] = cal();
	auto [b, B] = cal();
	map<char, int>mm;
	for (auto& i : A)
	{
		mm[i]++;
	}
	for (auto& i : B)
	{
		if (mm.find(i) == mm.end())
		{
			if (a && base.find(i) != string::npos)
			{
				a--;
				continue;
			}
			cout << "No";
			return 0;
		}
		if (--mm[i] == 0)
		{
			mm.erase(i);
		}
	}
	for (auto& [pa, pb] : mm)
	{
		if (b < pb || base.find(pa) == string::npos)
		{
			cout << "No";
			return 0;
		}
		b -= pb;
	}
	cout << ((a == b) ? "Yes" : "No");
	return 0;
}
