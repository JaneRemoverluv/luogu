#include <bits/stdc++.h>
using namespace std;
long long n ,l,k;
const int N = 100010;
long long q[N];
//贪心算法
long long my_count (int length)//要切的长度
{
    int cnt = 0;
    for(int i = 0 ; i<n ; i++)
    {
        long long ans=q[i];
        while(ans >= length)
        {
            cnt++;
            ans-=length;
            //printf("%d,%d\n",cnt,ans);
        }
    }
    return (long long)cnt;
}
int bsearch(int l,int r)
{
    while(l<r)
    {
    int mid = (l+r+1)>>1;
    if(my_count(mid) >= k) l = mid;
    else r = mid-1;
    }
    //printf("%d\n",l);
    if(my_count(l) <k) return 0;
    return l;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 0; i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    int l = 0,r = 1e8+10;
    printf("%d",bsearch(l,r));
    return 0;
}
