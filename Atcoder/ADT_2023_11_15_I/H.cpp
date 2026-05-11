#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	map<int, map<int, pii>> nxt; // 원소, 버전
	map<int, pii> version;
	map<int, int> res;
	int cnt = 1, ver = 1, now = -1, id = 0;
	// cnt = 새롭게 할 그 버전, ver = 현재 버전, now = 현재 원소, id = 원소의 고유번호
	while (q--)
	{
		string str;
		cin >> str;
		if (str == "DELETE")
		{
			if (nxt.find(ver) == nxt.end() || nxt[ver].find(now) == nxt[ver].end())
			{
				now = -1;
			}
			else
			{
				auto [A, B] = nxt[ver][now];
				now = A, ver = B;
			}
			cout << ((now == -1) ? -1 : res[now]) << ' ';
			continue;
		}
		int a = 0;
		cin >> a;
		if (str == "ADD")
		{
			res[++id] = a;
			nxt[cnt][id] = make_pair(now, ver);
			if (cnt != ver)
			{
				ver = cnt;
			}
			now = id;
		}
		if (str == "SAVE")
		{
			version[a] = make_pair(now, ver);
		}
		if (str == "LOAD")
		{
			if (version.find(a) == version.end())
			{
				ver = 0, now = -1;
			}
			else
			{
				cnt++;
				auto [A, B] = version[a];
				now = A, ver = B;
			}
		}
		cout << ((now == -1) ? -1 : res[now]) << ' ';
	}
	return 0;
}
