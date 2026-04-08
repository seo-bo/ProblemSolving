#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int di[5001];
int prefix[5001][5001];

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 2; i <= 5000; ++i)
	{
		if (!di[i])
		{
			for (int j = i; j <= 5000; j += i)
			{
				if (!di[j])
				{
					di[j] = i;
				}
			}
		}
	}
	for (int i = 2; i <= 5000; ++i)
	{
		int p = i;
		while (p > 1)
		{
			prefix[i][di[p]]++;
			p /= di[p];
		}
		for (int j = 2; j <= 5000; ++j)
		{
			prefix[i][j] += prefix[i - 1][j];
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		int flag = 1;
		for (int j = 2; j <= 5000; ++j)
		{
			int A = prefix[a][j] - prefix[b][j] - prefix[a - b][j];
			int B = prefix[c][j] - prefix[d][j] - prefix[c - d][j];
			if (A && B)
			{
				flag = 0;
				break;
			}
		}
		cout << flag << '\n';
	}
	return 0;
}