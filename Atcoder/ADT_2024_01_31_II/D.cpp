#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string one = "H , D , C , S ", two = "A , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , T , J , Q , K";
	int n = 0;
	cin >> n;
	set<string>s;
	for (int i = 0; i < n; ++i)
	{
		int f1 = 0, f2 = 0;
		string str;
		cin >> str;
		for (auto& j : one)
		{
			if (j == str[0])
			{
				f1 = 1;
				break;
			}
		}
		for (auto& j : two)
		{
			if (j == str[1])
			{
				f2 = 1;
				break;
			}
		}
		if (f1 && f2 && s.find(str) == s.end())
		{
			s.insert(str);
			continue;
		}
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}
