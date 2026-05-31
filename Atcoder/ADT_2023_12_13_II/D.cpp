#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii> v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		v[i].second = i;
		string str;
		cin >> str;
		for (int j = i + 1; j <= n; ++j)
		{
			if (str[j - 1] == 'x')
			{
				v[j].first++;
			}
			else
			{
				v[i].first++;
			}
		}
	}
	sort(v.begin() + 1, v.end(), [&](const pii &a, const pii &b)
		 {
		if(a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first > b.first; });
	for (int i = 1; i <= n; ++i)
	{
		cout << v[i].second << ' ';
	}
	return 0;
}
