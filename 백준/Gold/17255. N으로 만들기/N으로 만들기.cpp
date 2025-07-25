#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	str = " " + str;
	int len = str.size();
	set<string>visited;
	function<void(int, int, int, string, string)> dfs = [&](int left, int idx, int right, string pivot, string cur)
		{
			if (left == 0 && right == len)
			{
				visited.insert(pivot);
				return;
			}
			if (!idx)
			{
				for (int i = 1; i < len; ++i)
				{
					string temp = "";
					temp += str[i];
					dfs(i - 1, i, i + 1, temp, temp);
				}
			}
			else
			{
				if (left)
				{
					dfs(left - 1, idx, right, pivot + str[left] + cur, str[left] + cur);
				}
				if (right != len)
				{
					dfs(left, idx, right + 1, pivot + cur + str[right], cur + str[right]);
				}
			}
		};
	dfs(0, 0, 0, "", "");
	cout << visited.size();
	return 0;
}