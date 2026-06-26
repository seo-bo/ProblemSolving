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
	string str;
	cin >> str;
	int len = str.size();
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		string temp;
		cin >> temp;
		int tlen = temp.size();
		if (str == temp)
		{
			ans.push_back(i);
			continue;
		}
		if (!(len - 1 <= tlen && tlen <= len + 1))
		{
			continue;
		}
		int left = 0, right = 0;
		for (int j = 0; j < min(len, tlen); ++j)
		{
			if (str[j] == temp[j])
			{
				left = j + 1;
				continue;
			}
			break;
		}
		for (int j = 0; j < min(len, tlen); ++j)
		{
			if (str[len - 1 - j] == temp[tlen - 1 - j])
			{
				right = j + 1;
				continue;
			}
			break;
		}
		if (len == tlen && left + right >= len - 1)
		{
			ans.push_back(i);
		}
		if (len != tlen && left + right >= min(len, tlen))
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
