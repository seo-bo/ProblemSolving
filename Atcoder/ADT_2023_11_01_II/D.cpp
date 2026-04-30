#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	map<char, char>mm = { {'-','-'}, {'W','L'}, {'L','W'},{'D','D'} };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[j][i] != mm[v[i][j]])
			{
				cout << "incorrect";
				return 0;
			}
		}
	}
	cout << "correct";
	return 0;
}
