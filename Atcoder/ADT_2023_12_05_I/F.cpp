#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<int> s;
	int n = 0;
	cin >> n;
	int free = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (s.find(a) == s.end())
		{
			s.insert(a);
			continue;
		}
		free++;
	}
	for (int i = 1;; ++i)
	{
		if (s.find(i) != s.end())
		{
			s.erase(i);
			continue;
		}
		int need = 2 - free;
		if (need <= 0)
		{
			free -= 2;
		}
		else if (s.size() >= need)
		{
			for (int i = 0; i < need; ++i)
			{
				s.erase(prev(s.end()));
			}
			free -= 2 - need;
		}
		else
		{
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}
