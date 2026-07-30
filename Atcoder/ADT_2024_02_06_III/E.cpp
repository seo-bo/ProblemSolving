#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, char>pic;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int len = s.size();
	deque<pic>a, b;
	for (int i = 0; i < len; ++i)
	{
		a.push_back(make_pair(i + 1, s[i]));
	}
	for (int i = 0; i < len + 1; ++i)
	{
		b.push_back(make_pair(i + 1, t[i]));
	}
	while (!a.empty())
	{
		if (a.front().second == b.front().second)
		{
			a.pop_front();
			b.pop_front();
		}
		else
		{
			a.pop_back();
			b.pop_back();
		}
	}
	cout << b.front().first;
	return 0;
}
