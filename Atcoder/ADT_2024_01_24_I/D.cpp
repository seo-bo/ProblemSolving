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
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int a = (A[1] - A[0] == 1 || A[1] - A[0] == 4), b = (B[1] - B[0] == 1 || B[1] - B[0] == 4);
	cout << ((a == b) ? "Yes" : "No");
	return 0;
}
