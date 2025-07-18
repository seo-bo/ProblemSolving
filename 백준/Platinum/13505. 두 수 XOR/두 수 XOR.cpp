#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Trie
{
	Trie* child[2];
	Trie() { child[0] = child[1] = nullptr; }
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	Trie* root = new Trie();
	auto insert = [&](string& str)
		{
			Trie* cur = root;
			for (auto& i : str)
			{
				int p = i - '0';
				if (!cur->child[p])
				{
					cur->child[p] = new Trie();
				}
				cur = cur->child[p];
			}

		};
	ll ans = 0;
	vector<string>v;
	for (int i = 0; i < n; ++i)
	{
		string str(40, '0');
		ll temp = 0;
		cin >> temp;
		for (int j = 0; j < 40; ++j)
		{
			if (temp & (1LL << (39 - j)))
			{
				str[j] = '1';
			}
		}
		insert(str);
		v.push_back(str);
	}
	auto search = [&](string& str)
		{
			Trie* cur = root;
			ll res = 0;
			for (int i = 0; i < 40; ++i)
			{
				int p = str[i] - '0';
				if (cur->child[p ^ 1])
				{
					res |= (1LL << (39 - i));
					cur = cur->child[p ^ 1];
				}
				else
				{
					cur = cur->child[p];
				}
			}
			return res;
		};
	for (auto& i : v)
	{
		ans = max(ans, search(i));
	}
	cout << ans;
	return 0;
}