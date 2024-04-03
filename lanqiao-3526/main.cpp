#include <bits/stdc++.h>
using namespace std;

void worker(long long n, long long m, long long k)
{
    long long s = 1;
    // 最左结点i*m-m+2 最右结点i*m+1
    long long lchild = k, rchild = k;
    for (int h = 2;; h++)
    {
        // 第h层
        lchild = lchild * m - m + 2;
        rchild = rchild * m + 1;

        if (lchild > n)
        {
            // 没有这层
            break;
        }
        if (rchild >= n)
        {
            // 最后一层
            s += n - lchild + 1;
            break;
        }
        else
            s += rchild - lchild + 1; // 这一层结点数
    }
    cout << s << endl;
}
int main()
{
    int T;
    cin >> T;
    long long n, m, k;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> m >> k;
        worker(n, m, k);
    }
    return 0;
}