#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		int len = str.size(), idx = 0;
		function<string()> dfs = [&]
			{
				if (str[idx++] != 'x')
				{
					return string(1, str[idx - 1]);
				}
				vector<string>temp(4);
				for (int i = 0; i < 4; ++i)
				{
					temp[i] = dfs();
				}
				string res = "x" + temp[2] + temp[3] + temp[0] + temp[1];
				return res;
			};
		cout << dfs() << '\n';
	}
	return 0;
}
