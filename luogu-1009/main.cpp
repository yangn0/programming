#include <bits/stdc++.h>

using namespace std;

string add(string a, string b)
{
    string sum;
    int alen = a.length();
    int blen = b.length();
    int maxlen, tempa, tempb;
    if (alen < blen)
    {
        maxlen = blen;
    }
    else
        maxlen = alen;
    int jinwei = 0;
    for (int i = 1; i <= maxlen; i++)
    {
        if (i > alen)
        {
            tempa = 0;
        }
        else
            tempa = (int)a[alen - i] - 48;
        if (i > blen)
        {
            tempb = 0;
        }
        else
            tempb = (int)b[blen - i] - 48;

        int s = tempa + tempb + jinwei;
        jinwei = 0;
        if (s / 10 >= 1)
            jinwei = 1;
        sum.insert(sum.begin(), s % 10 + 48);
        if(i==maxlen && jinwei==1){
            sum.insert(sum.begin(),'1');
        }
    }
    return sum;
}

string mul(string a, string b)
{
    string sum="0";
    int c;
    for(int i=1;i<=b.length();i++){
        c=(int)b[b.length()-i]-48;
        while(c--) sum=add(sum,a);
        a.push_back('0');
    }
    return sum;
}

string calcu(int i)
{
    string s="1";

    while(i){
        s=mul(s,to_string(i));
        i--;
    }

    return s;
}

int main()
{
    int n;
    cin >> n;

    string S = "0";
    for (int i = 1; i <= n; i++)
    {
        S=add(S,calcu(i));
    }
    cout<<S;
    return 0;
}