#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	set<string>s;
	int pivot = -1, ans = -1;
	for (int i = 0; i < n; ++i)
	{
		string str;
		int a = 0;
		cin >> str >> a;
		if (s.find(str) != s.end())
		{
			continue;
		}
		if (pivot < a)
		{
			pivot = a, ans = i + 1;
		}
		s.insert(str);
	}
	cout << ans;
	return 0;
}
