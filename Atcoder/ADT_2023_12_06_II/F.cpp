#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, set<int>> card;
	map<int, multiset<int>> box;
	int n = 0, q = 0;
	cin >> n >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			box[c].insert(b);
			card[b].insert(c);
		}
		else if (a == 2)
		{
			for (auto &i : box[b])
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
		else
		{
			for (auto &i : card[b])
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
