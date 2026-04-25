#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	int alen = A.size(), blen = B.size();
	if (alen > blen)
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < alen; ++i)
	{
		if(A[i] != B[i])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
