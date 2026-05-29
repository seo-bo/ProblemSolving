#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<char, int> pci;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	auto cal = [&](string str)
	{
		vector<pci> pos;
		char a = str[0];
		int cnt = 0;
		for (auto &i : str)
		{
			if (i == a)
			{
				cnt++;
			}
			else
			{
				pos.push_back(make_pair(a, cnt));
				a = i;
				cnt = 1;
			}
		}
		pos.push_back(make_pair(a, cnt));
		return pos;
	};
	vector<pci> va = cal(A), vb = cal(B);
	if (va.size() != vb.size())
	{
		cout << "No";
		return 0;
	}
	int len = va.size();
	for (int i = 0; i < len; ++i)
	{
		auto [_, acnt] = va[i];
		auto [__, bcnt] = vb[i];
		if (acnt > bcnt || _ != __)
		{
			cout << "No";
			return 0;
		}
		else if (acnt < bcnt && acnt == 1)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
