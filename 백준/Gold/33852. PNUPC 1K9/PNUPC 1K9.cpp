#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	int k = 0, p = 0;
	cin >> str >> k >> p;
	map<char, int>mm;
	for (int i = 1; i <= 9; ++i)
	{
		mm[char(i + '0')] = i;
	}
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		mm[i] = i - 'A' + 10;
	}
	int len = str.size();
	reverse(str.begin(), str.end());
	vector<int>v;
	int base = 1, sum = 0;
	for (auto& i : str)
	{
		int pivot = mm[i];
		v.push_back(pivot * base % p);
		sum = (sum + v.back()) % p;
		base = (base * 36) % p;
	}
	if (sum == k)
	{
		cout << 0;
		return 0;
	}
	if (len == 1 && k > 35)
	{
		cout << -1;
		return 0;
	}
	base = 1;
	for (auto& i : v)
	{
		int pivot = (sum - i + p) % p;
		for (int j = 0; j < 36; ++j)
		{
			if ((pivot + base * j) % p == k)
			{
				cout << 1;
				return 0;
			}
		}
		base = (base * 36) % p;
	}
	cout << 2;
	return 0;
}