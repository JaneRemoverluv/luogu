#include <bits/stdc++.h>
using namespace std;
long long n, k;
const int N = 100010;
long long q[N];

long long my_count(int length) // 长度 length 下能切出的总段数
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += q[i] / length;   // 更好的贪心算法
    return cnt;
}

long long bsearch(long long l, long long r)
{
    while (l < r)
    {
        long long mid = (l + r + 1) >> 1;
        if (my_count(mid) >= k) l = mid;
        else r = mid - 1;
    }
    if (l == 0 || my_count(l) < k) return 0;
    return l;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &q[i]);
    long long l = 0, r = 1e8 + 10;
    printf("%lld", bsearch(l, r));
    return 0;
}
