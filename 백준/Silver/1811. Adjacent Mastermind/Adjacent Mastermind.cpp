#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		string a, b;
		cin >> a;
		if (a == "#")
		{
			break;
		}
		cin >> b;
		int len = a.size();
		int a1 = 0, a2 = 0, a3 = 0;
		vector<bool>avis(len, false);
		vector<bool>bvis(len, false);
		for (int i = 0; i < len; ++i)
		{
			if (a[i] == b[i])
			{
				avis[i] = true;
				bvis[i] = true;
				a1++;
			}
		}
		for (int i = 0; i < len; ++i)
		{
			if (bvis[i])
			{
				continue;
			}
			if (i - 1 >= 0)
			{
				if (!avis[i - 1] && b[i] == a[i - 1])
				{
					avis[i - 1] = true;
					bvis[i] = true;
					a2++;
					continue;
				}
			}
			if (i + 1 < len)
			{
				if (!avis[i + 1] && b[i] == a[i + 1])
				{
					avis[i + 1] = true;
					bvis[i] = true;
					a2++;
				}
			}
		}
		multiset<char>aa, bb;
		for (int i = 0; i < len; ++i)
		{
			if (!avis[i])
			{
				aa.insert(a[i]);
			}
			if (!bvis[i])
			{
				bb.insert(b[i]);
			}
		}
		for (auto& i : bb)
		{
			if (aa.find(i) != aa.end())
			{
				a3++;
				aa.erase(i);
			}
		}
		cout << format("{}: {} black, {} grey, {} white\n", b, a1, a2, a3);
	}
	return 0;
}