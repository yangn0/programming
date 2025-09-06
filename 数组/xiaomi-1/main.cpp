#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p, q;
    cin >> n >> p >> q;

    long long sum = 0;
    vector<vector<int>> in;
    map<int, vector<int>> left_map, right_map;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
            left_map[b].push_back(c);
        else
            right_map[b].push_back(c);
    }

    for (auto s : left_map)
    {
        int size_num = s.first;
        vector<int> left_color_vec = s.second;

        if (right_map.count(size_num))
        {
            vector<int> right_color_vec = right_map[size_num];
            vector<int> min_color_vec,max_color_vec;
            if(left_color_vec.size()>right_color_vec.size()){
                min_color_vec=right_color_vec;
                max_color_vec=left_color_vec;
            }else {
                min_color_vec=left_color_vec;
                max_color_vec=right_color_vec;
            }

            // 有几个重复的？
            int re=0;
            // sort(left_color_vec.begin(),left_color_vec.end());
            // sort(right_color_vec.begin(),right_color_vec.end());
            // int left=0,right=0;
            for(int i=0;i<min_color_vec.size();i++){
                int t=min_color_vec[i];
                for(int u=0;u<max_color_vec.size();u++){
                    if(t==max_color_vec[u]){
                        re++;
                        max_color_vec.erase(max_color_vec.begin()+u);
                        break;
                    }
                }
            }
            int diff_color_num=min_color_vec.size()-re;
            sum+=diff_color_num*q;
            sum+=re*p;
        }
    }
    cout<<sum;
}