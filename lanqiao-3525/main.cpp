#include <bits/stdc++.h>
using namespace std;

int check(int a, int b)
{
    if (__gcd(a, b) != 1)
        return 1;
    return 0;
}
int main()
{
    int n;
    int flag=0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1;j<n; j++)
        {
            if (check(A[i], A[j]))
            {
                cout << i + 1 << " "<< j + 1;
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }

    return 0;
}