#include <bits/stdc++.h>
#include "sauce.h"
using namespace std;
typedef long long ll;

int solve(int n)
{
	vector<vector<int>>v(6);
	int idx = 0, now = 0;
	while (now < n)
	{
		v[idx].push_back(now++);
		idx = (idx + 1) % 6;
	}
	int ans = 0;
	vector<int>base = { 0, 6, -3, 1 };
	for (int i = 1; i < (1 << 6); ++i)
	{
		int p = __builtin_popcount(i);
		if (p > 3)
		{
			continue;
		}
		vector<int>temp;
		for (int j = 0; j < 6; ++j)
		{
			if (i & (1 << j))
			{
				for (auto& k : v[j])
				{
					temp.push_back(k);
				}
			}
		}
		ans += base[p] * query(temp);
	}
	return ans;
}