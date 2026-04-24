#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>pre(n + 1, -1), nxt(n + 1, -1);
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			nxt[b] = c, pre[c] = b;
		}
		else if (a == 2)
		{
			cin >> c;
			nxt[pre[c]] = -1, pre[c] = -1;
		}
		else
		{
			int x = b;
			while (pre[x] != -1)
			{
				x = pre[x];
			}
			vector<int>temp;
			while (x != -1)
			{
				temp.push_back(x);
				x = nxt[x];
			}
			cout << temp.size() << ' ';
			for (auto& i : temp)
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
