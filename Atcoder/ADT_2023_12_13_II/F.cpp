#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int> v(9);
	for (auto &i : v)
	{
		cin >> i;
	}
	vector<int> per(9);
	iota(per.begin(), per.end(), 0);
	int ans = 0, cnt = 0;
	auto cal = [&](vector<vector<int>> &p)
	{
		for (auto &i : p)
		{
			if (i[0] == i[1])
			{
				return true;
			}
		}
		return false;
	};
	do
	{
		vector<vector<int>> x(3), y(3), diag(2);
		for (auto &i : per)
		{
			int nx = i / 3, ny = i % 3, co = v[i];
			x[nx].push_back(co);
			y[ny].push_back(co);
			if (nx == 1 && ny == 1)
			{
				diag[0].push_back(co);
				diag[1].push_back(co);
			}
			if (nx == 1 || ny == 1)
			{
				continue;
			}
			if (nx == ny)
			{
				diag[0].push_back(co);
			}
			else
			{
				diag[1].push_back(co);
			}
		}
		int flag = cal(x) | cal(y) | cal(diag);
		ans += flag;
		cnt++;
	} while (next_permutation(per.begin(), per.end()));
	cout << fixed << setprecision(15) << double(cnt - ans) / cnt;
	return 0;
}
