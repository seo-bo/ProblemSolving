#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<string, int>mm;
	unordered_set<string>prefix;
	int n = 0;
	cin >> n;
	while (n--)
	{
		string str, temp;
		cin >> str;
		string ans = str;
		if (++mm[str] != 1)
		{
			ans += to_string(mm[str]);
		}
		int flag = 0;
		for (auto& i : str)
		{
			temp += i;
			if (!flag && prefix.find(temp) == prefix.end())
			{
				flag = 1;
				ans = temp;
			}
			prefix.insert(temp);
		}
		cout << ans << '\n';
	}
	return 0;
}