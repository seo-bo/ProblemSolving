#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, sum = 16;
	cin >> n >> m;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
		sum -= i.size();
	}
	vector<int>per(n);
	iota(per.begin(), per.end(), 0);
	set<string>s;
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	function<void(int, string)> dfs = [&](int depth, string str)
		{
			if (depth == n - 1)
			{
				str += v[per[depth]];
				if (str.size() >= 3 && s.find(str) == s.end())
				{
					cout << str;
					exit(0);
				}
				return;
			}
			if (sum == 0)
			{
				return;
			}
			for (int i = 1; i <= sum; ++i)
			{
				string base(i, '_');
				sum -= i;
				dfs(depth + 1, str + v[per[depth]] + base);
				sum += i;
			}
		};
	do
	{
		dfs(0, "");
	} while (next_permutation(per.begin(), per.end()));
	cout << -1;
	return 0;
}
