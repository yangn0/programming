#include <bits/stdc++.h>
using namespace std;

int N, num,flag=0;
int posSet[20 * 20] = {0};
int s[600];

int isEmpty(int heng[], int shu[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (heng[i] != 0)
            return 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (shu[i] != 0)
            return 0;
    }
    return 1;
}

int dfs(int pos, int heng[], int shu[], int N, int k)
{
    if(flag==1)
        // 已经找到答案，直接返回
        return 0;
    if (heng[pos % N] <= 0 || shu[pos / N] <= 0)
        // 当前位置 标靶数等于0
        return 0;
    if (posSet[pos] == 1)
        // 当前位置 已经来过
        return 0;

    s[k] = pos; // 第k步的位置

    posSet[pos] = 1;
    heng[pos % N]--;
    shu[pos / N]--;

    if (pos == N * N - 1 && isEmpty(heng, shu, N))
    {
        // 到达终点
        num = k;
        flag=1;
        return 1;
    }

    // left
    if (pos % N != 0)
    {
        pos--;
        dfs(pos, heng, shu, N, k + 1);
        pos++;
    }
    // right
    if (pos % N != N - 1)
    {
        pos++;
        dfs(pos, heng, shu, N, k + 1);
        pos--;
    }
    // up
    if (pos >= N)
    {
        pos = pos - N;
        dfs(pos, heng, shu, N, k + 1);
        pos = pos + N;
    }
    // down
    if (pos < N * N - N)
    {
        pos = pos + N;
        dfs(pos, heng, shu, N, k + 1);
        pos = pos - N;
    }

    posSet[pos] = 0;
    heng[pos % N]++;
    shu[pos / N]++;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int heng[N], shu[N];
    for (int i = 0; i < N; i++)
        cin >> heng[i];
    for (int i = 0; i < N; i++)
        cin >> shu[i];

    int pos = 0;

    dfs(pos, heng, shu, N, 1);

    for (int i = 1; i <= num; i++)
    {
        cout << s[i] <<" ";
    }
    return 0;
}