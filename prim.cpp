#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 10;
const int INF = 1 << 30;
int n, m;
int Map[maxn][maxn];//存图
int lowcost[maxn], mst[maxn];
void prim(int u)//最小生成树起点
{
    int sum_mst = 0;//最小生成树权值
    for(int i = 1; i <= n; i++)//初始化两个数组
    {
        lowcost[i] = Map[u][i];
        mst[i] = u;
    }
    mst[u] = -1;//设置成-1表示已经加入mst
    for(int i = 1; i < n; i++)//此处只需要迭代n-1次即可
    {
        int minn = INF;
        int v = -1;
        //在lowcost数组中寻找未加入mst的最小值
        for(int j = 1; j <= n; j++)
        {
            if(mst[j] != -1 && lowcost[j] < minn)
            {
                v = j;
                minn = lowcost[j];
            }
        }
        if(v != -1)//v=-1表示未找到最小的边,
        {//v表示当前距离mst最短的点
            printf("%d %d %d\n", mst[v], v, lowcost[v]);//输出路径
            mst[v] = -1;
            sum_mst += lowcost[v];
            for(int j = 1; j <= n; j++)//更新最短边
            {
                if(mst[j] != -1 && lowcost[j] > Map[v][j])
                {
                    lowcost[j] = Map[v][j];
                    mst[j] = v;
                }
            }
        }
    }
    printf("weight of mst is %d\n", sum_mst);
}
int main()
{
    cin >> n >> m;
    memset(Map, 0, sizeof(Map));
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Map[u][v] = Map[v][u] = w;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)Map[i][j] = 0;
            else if(!Map[i][j])Map[i][j] = INF;
        }
    }
    prim(1);
    return 0;
}

/*
输入样例
7 9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
*/

/*
输出样例
1 6 10
6 5 25
5 4 22
4 3 12
3 2 16
2 7 14
weight of mst is 99
*/