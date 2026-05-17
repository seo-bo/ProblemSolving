#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	int len = A.size();
	for (int i = 0; i < len; ++i)
	{
		for (auto &j : {i - 1, i, i + 1})
		{
			if (j >= 0 && j < len)
			{
				swap(A[j], A[i]);
				if (A == B)
				{
					cout << "Yes";
					return 0;
				}
				swap(A[j], A[i]);
			}
		}
	}
	cout << "No";
	return 0;
}
