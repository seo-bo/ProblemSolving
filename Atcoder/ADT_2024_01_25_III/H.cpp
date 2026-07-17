#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>in;
	set<int>out;
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		in[v[i]]++;
	}
	for (int i = 0; i <= n + 2; ++i)
	{
		if (in.find(i) == in.end())
		{
			out.insert(i);
		}
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int pre = v[a], nxt = b;
		v[a] = b;
		if (--in[pre] == 0)
		{
			in.erase(pre);
			out.insert(pre);
		}
		if (++in[nxt] == 1)
		{
			out.erase(nxt);
		}
		cout << *out.begin() << '\n';
	}
	return 0;
}
