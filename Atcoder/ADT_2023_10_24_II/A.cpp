#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<string>v = { "ACE","BDF","CEG","DFA","EGB","FAC","GBD" };
	string str;
	cin >> str;
	for (auto& i : v)
	{
		if (i == str)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
