#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	deque<char>dq;
	for (auto& i : str)
	{
		dq.push_back(i);
	}
	while (!dq.empty() && dq.back() == 'a')
	{
		dq.pop_back();
		if (!dq.empty() && dq.front() == 'a')
		{
			dq.pop_front();
		}
	}
	while (!dq.empty())
	{
		if (dq.front() != dq.back())
		{
			cout << "No";
			return 0;
		}
		dq.pop_front();
		if (!dq.empty())
		{
			dq.pop_back();
		}
	}
	cout << "Yes";
	return 0;
}
