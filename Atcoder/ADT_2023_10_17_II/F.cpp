#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int>pci;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>alpha(26);
	deque<pci>A, B;
	string a, b;
	cin >> a >> b;
	int len = b.size();
	for (int i = 0; i < len - 1; ++i)
	{
		A.push_back(make_pair(a[i], i + 1));
	}
	for (int i = 0; i < len; ++i)
	{
		B.push_back(make_pair(b[i], i + 1));
	}
	while (!A.empty())
	{
		if (!A.empty() && A.back().first == B.back().first)
		{
			A.pop_back(), B.pop_back();
		}
		if (!A.empty() && A.front().first == B.front().first)
		{
			A.pop_front(), B.pop_front();
		}
	}
	cout << B.front().second;
	return 0;
}
