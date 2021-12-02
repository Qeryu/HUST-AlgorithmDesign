// P2740 草地排水 Drainage Ditches
// https :  // www.luogu.com.cn/problem/P2740
// 使用Dinic网络流算法进行求解
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 210;
const int INF = 0x3f3f3f3f;

struct Edge {
    int next, to, flow;
} edges[N * 2];

int n, m, cntEdge, head[N];
int maxFlow, s, t, dep[N];

void addEdge(int x, int y, int f) {
    edges[cntEdge].next = head[x];
    edges[cntEdge].to = y;
    edges[cntEdge].flow = f;
    head[x] = cntEdge++;
}

/*
把图分为多层，一个点的层数对应其在BFS中的深度，也就是dep数组
返回值，为判断能否搜到t，能BFS搜到t则返回true
*/
bool bfs(int s) {
    queue<int> q;
    memset(dep, -1, sizeof(dep));
    dep[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int e = head[cur]; e != -1; e = edges[e].next) {
            int eTo = edges[e].to;
            int eFlow = edges[e].flow;
            if (eFlow > 0 && dep[eTo] == -1) {
                dep[eTo] = dep[cur] + 1;
                q.push(eTo);
            }
        }
    }
    return dep[t] != -1;
}

/*
遍历更新，依据BFS的结果对路径进行增广
dfs(cur, inFlow)表示对cur点流入inFlow的流量的结果
返回值为当前网络下可行的最大流量，一定小于等于inFlow
*/
int dfs(int cur, int inFlow) {
    // 搜到了终点
    if (cur == t) return inFlow;
    // 对所有能到达的点进行进一步DFS
    for (int e = head[cur]; e != -1; e = edges[e].next) {
        int eTo = edges[e].to;
        int eFlow = edges[e].flow;
        if (dep[eTo] == dep[cur] + 1 && eFlow != 0) {
            // df意为流量差，即当前网络下可行的最大流量
            int df = dfs(eTo, min(inFlow, eFlow));
            if (df > 0) {
                edges[e].flow -= df;
                edges[e ^ 1].flow += df;
                return df;
            }
        }
    }
    return 0;
}

void dinic() {
    int curFlow = 0;
    // 不断尝试通过BFS构建分层图
    while (bfs(s)) {
        curFlow = INF;
        while (curFlow) {
            // 构建成功后使用DFS进行增广，增广结果计入总结果
            curFlow = dfs(s, INF);
            maxFlow += curFlow;
        }
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    s = 1;
    t = m;
    for (int i = 1; i <= n; ++i) {
        int x, y, f;
        scanf("%d%d%d", &x, &y, &f);
        // 添加双向边
        addEdge(x, y, f);
        addEdge(y, x, 0);
    }
    dinic();
    printf("%d\n", maxFlow);
    return 0;
}