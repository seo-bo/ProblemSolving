#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<int>>row(h + 1, vector<int>(27)), col(w + 1, vector<int>(27));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			char a;
			cin >> a;
			row[i][a - 'a']++;
			col[j][a - 'a']++;
		}
	}
	int nh = h, nw = w;
	vector<int>vr(h + 1, 1), vc(w + 1, 1);
	for (int i = 0; i < h + w; ++i)
	{
		vector<int>A(27), B(27);
		for (int i = 1; i <= h && nw > 1; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				if (row[i][j] == nw && vr[i])
				{
					A[j]++;
					vr[i] = 0;
				}
			}
		}
		for (int i = 1; i <= w && nh > 1; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				if (col[i][j] == nh && vc[i])
				{
					B[j]++;
					vc[i] = 0;
				}
			}
		}
		for (int i = 0; i <= 26; ++i)
		{
			for (int j = 1; j <= w; ++j)
			{
				col[j][i] -= A[i];
			}
			for (int j = 1; j <= h; ++j)
			{
				row[j][i] -= B[i];
			}
			nh -= A[i], nw -= B[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			ans += vr[i] & vc[j];
		}
	}
	cout << ans;
	return 0;
}
