#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

vector<int> op1(vector<int> A, vector<int> B)
{
	vector<int> res(26);
	for (int i = 0; i < 26; ++i)
	{
		res[i] += A[i] + B[i];
	}
	return res;
}

vector<int> e1()
{
	return vector<int>(26);
}

ll op2(ll a, ll b)
{
	return a + b;
}

ll e2()
{
	return 0;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	segtree<vector<int>, op1, e1> alpha(n + 2);
	segtree<ll, op2, e2> inv(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		vector<int> temp(26);
		temp[str[i - 1] - 'a']++;
		alpha.set(i, temp);
		if (i >= 2)
		{
			inv.set(i - 1, (str[i - 2] > str[i - 1]));
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			char c;
			cin >> c;
			str[b - 1] = c;
			vector<int> temp(26);
			temp[c - 'a']++;
			alpha.set(b, temp);
			if (b >= 2)
			{
				inv.set(b - 1, (str[b - 2] > str[b - 1]));
			}
			if (b < n)
			{
				inv.set(b, (str[b - 1] > str[b]));
			}
		}
		else
		{
			int c = 0, flag = 1;
			cin >> c;
			if (inv.prod(b, c))
			{
				cout << "No\n";
				continue;
			}
			vector<int> now = alpha.prod(b, c + 1);
			vector<int> all = alpha.all_prod();
			for (int i = str[b - 1] - 'a' + 1; i < str[c - 1] - 'a'; ++i)
			{
				if (now[i] != all[i])
				{
					flag = 0;
					break;
				}
			}
			cout << ((flag) ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}
