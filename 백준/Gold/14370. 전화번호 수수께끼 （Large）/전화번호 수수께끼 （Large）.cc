#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int>psi;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<psi>v = { {"ZERO",0},{"TWO",2},{"FOUR",4},{"SIX",6},{"EIGHT",8},{"ONE",1}
		,{"FIVE",5},{"SEVEN",7},{"THREE",3},{"NINE",9} };
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		string str;
		cin >> str;
		vector<int>cnt(26, 0);
		for (auto& i : str)
		{
			cnt[i - 'A']++;
		}
		vector<int>ans;
		int mask = 0;
		for (auto& [a, b] : v)
		{
			int temp = INT_MAX, mask = 0, p = -1;
			for (auto& i : a)
			{
				int pp = i - 'A';
				temp = min(temp, cnt[pp]);
				if (mask & (1 << (pp)))
				{
					p = pp;
					temp = min(temp, cnt[pp] / 2);
				}
				mask |= (1 << pp);
			}
			for (auto& i : a)
			{
				cnt[i - 'A'] -= temp;
			}
			for (int i = 0; i < temp; ++i)
			{
				ans.push_back(b);
			}
		}
		sort(ans.begin(), ans.end());
		cout << format("Case #{}: ", i);
		for (auto& i : ans)
		{
			cout << i;
		}
		cout << '\n';
	}
	return 0;
}