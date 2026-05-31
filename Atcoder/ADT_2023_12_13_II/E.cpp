#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> A(n + 1), B(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> B[i];
	}
	set<int> s = {A[1], B[1]};
	for (int i = 2; i <= n; ++i)
	{
		set<int> temp;
		for (auto &j : s)
		{
			for (auto &z : {A[i], B[i]})
			{
				if (abs(j - z) <= k)
				{
					temp.insert(z);
				}
			}
		}
		if (temp.empty())
		{
			cout << "No";
			return 0;
		}
		s = move(temp);
	}
	cout << "Yes";
	return 0;
}
