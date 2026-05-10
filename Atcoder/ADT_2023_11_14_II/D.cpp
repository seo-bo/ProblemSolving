#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	string base = str + str;
	int len = str.size();
	string maxi(len, 'a'), mini(len, 'z');
	for (int i = 0; i < len; ++i)
	{
		string temp = base.substr(i, len);
		maxi = max(maxi,temp), mini = min(mini,temp);
	}
	cout << mini << '\n' << maxi;
	return 0;
}
