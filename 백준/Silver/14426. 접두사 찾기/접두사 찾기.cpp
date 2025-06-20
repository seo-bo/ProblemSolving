#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
	map<char, Node*>child;
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	Node* root = new Node();
	auto insert = [&](string& str)
		{
			Node* cur = root;
			for (auto& i : str)
			{
				if (!cur->child[i])
				{
					cur->child[i] = new Node();
				}
				cur = cur->child[i];
			}
		};
	auto search = [&](string& str)
		{
			Node* cur = root;
			for (auto& i : str)
			{
				if (!cur->child[i])
				{
					return false;
				}
				cur = cur->child[i];
			}
			return true;
		};
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		insert(str);
	}
	int ans = 0;
	while (m--)
	{
		string str;
		cin >> str;
		if (search(str))
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}