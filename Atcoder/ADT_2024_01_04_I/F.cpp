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
	int a = 0, b = 0;
	while (!dq.empty() && dq.front() == 'a')
	{
		dq.pop_front();
		a++;
	}
	if (dq.empty())
	{
		cout << "Yes";
		return 0;
	}
	while (!dq.empty() && dq.back() == 'a')
	{
		dq.pop_back();
		b++;
	}
	if (a > b)
	{
		cout << "No";
		return 0;
	}
	int len = dq.size();
	for (int i = 0; i < len / 2; ++i)
	{
		if (dq[i] != dq[len - i - 1])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
