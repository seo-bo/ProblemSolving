#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int a = 0, b = 0;
	for (auto& i : str)
	{
		a += (i == 'o');
		b += (i == '?');
	}
	if (a > 4)
	{
		cout << 0;
		return 0;
	}
	set<int>s;
	int n = a + b, base = (1 << a) - 1;
	function<void(int, int, int)> dfs = [&](int depth, int mask, int num)
		{
			if (depth == 4)
			{
				if ((base & mask) == base)
				{
					s.insert(num);
				}
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				dfs(depth + 1, mask | (1 << i), num * 10 + i);
			}
		};
	dfs(0, 0, 0);
	cout << s.size();
	return 0;
}
