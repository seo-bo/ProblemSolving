#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	string str;
	cin >> str;
	for (auto& i : str)
	{
		if (i == 'A')
		{
			continue;
		}
		int pivot = 'Z' + 1 - i;
		if (k >= pivot)
		{
			i = 'A';
			k -= pivot;
		}
	}
	if (k)
	{
		int p = (str.back() - 'A' + k) % 26;
		str.back() = char(p + 'A');
	}
	cout << str;
	return 0;
}