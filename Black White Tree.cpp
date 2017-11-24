#include <bits/stdc++.h>
using namespace std;

#define N 111111

vector<int> adj[N];
int col[N];
int parent[N];
int mx[N];
int mn[N];
vector<int> res;
int ans, ansi;

void compute(int i, int p) {
    parent[i] = p;
    mx[i] = +col[i];
    mn[i] = -col[i];
    for (int j : adj[i]) {
        if (j == p) continue;
        compute(j, i);
        mx[i] += max(0, mx[j]);
        mn[i] += max(0, mn[j]);
    }
    int curr = max(mx[i], mn[i]);
    if (ans < curr) {
        ans = curr;
        ansi = i;
    }
}

void get(int i, bool ismx) {
    res.push_back(i);
    for (int j : adj[i]) {
        if (j == parent[i]) continue;
        if ((ismx ? mx : mn)[j] > 0) get(j, ismx);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &col[i]);
        if (!col[i]) col[i] = -1;
        parent[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    compute(0, -1);
    get(ansi, ans == mx[ansi]);

    printf("%d\n%d\n", ans, int(res.size()));
    for (int i = 0; i < res.size(); i++) {
        printf("%d%c", res[i] + 1, " \n"[i == res.size() - 1]);
    }
}





#include <bits/stdc++.h>
using namespace std;

const int maxN = 100009;

int n, c[maxN], logB[maxN], logW[maxN], ans, ansnode;
vector <int> v[maxN], answer;
bool f[maxN];

void input() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}


int Ssize, Scen;

int sizeC(int x, int from) {

    if (f[x]) {
        return 0;
    }

    int sizeN = 1;
    for (int y : v[x]) {
        if (y != from && !f[y]) {
            sizeN += sizeC(y, x);
        }
    }

    if (Scen == 0 && sizeN * 2 >= Ssize) {
        Scen = x;
    }

    return sizeN;
}


bool lg = false;

void dfs(int x, int from, int &nB, int &nW) {
    if (c[x] == 1) {
        nB = 1;
        nW = -1;
    } else {
        nB = -1;
        nW = 1;
    }

    int nnB = 0;
    int nnW = 0;

    for (int y : v[x]) {
        if (y != from && !f[y]) {
            dfs(y, x, nnB, nnW);
            nB += nnB;
            nW += nnW;
        }
    }

    nB = max(nB, 0);
    nW = max(nW, 0);
    if (lg) {
        logB[x] = nB;
        logW[x] = nW;
    }
}

void sol(int x) {
    Ssize = sizeC(x, x);
    Scen = 0;
    sizeC(x,x);

    if (f[Scen]) return;

    int B = 0, W = 0;
    dfs(Scen, Scen, B, W);

    if (B >= ans) {
        ans = B;
        ansnode = Scen;
    }

    if (W >= ans) {
        ans = W;
        ansnode = Scen;
    }

    f[Scen] = 1;

    for (int y : v[Scen]) {
        if (!f[y]) {
            sol(y);
        }
    }
}


void dfsA(int x, int from) {
    if (logB[x] == 0) return;

    answer.push_back(x);

    for (int y : v[x]) {
        if (y != from) {
            dfsA(y, x);
        }
    }
}

void output() {
    lg = 1;
    int B = 0, W = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
    }
    dfs(ansnode, ansnode, B, W);

    if (B < W) {
        for (int i = 1; i <= n; i++) {
            swap(logB[i], logW[i]);
        }
        swap(B, W);
    }

    dfsA(ansnode, ansnode);

    printf("%d\n%d\n", B, int(answer.size()));
    for (int i = 0; i + 1 < answer.size(); i++){
        printf("%d ",answer[i]);
    }
    printf("%d\n",answer.back());
}

int main() {
    input();
    sol(1);
    output();
    return 0;
}



#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#include <list>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 10000000
#define SQ 317
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,sz,cur,sum,n,c, maxlvl,q,z;
ll a[100500];
ll dp[100500][2];
vector<ll> g[100500], f[100500], ans;
void dfs(ll v, ll p = -1)
{
    if (a[v] == 0)
        dp[v][0] = 1, dp[v][1] = -1;
    else
        dp[v][0] = -1, dp[v][1] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            f[v].push_back(to);
            dfs(to, v);
            if (dp[to][0] > 0)
                dp[v][0] += dp[to][0];
            if (dp[to][1] > 0)
                dp[v][1] += dp[to][1];
        }
    }
}
void dfs2(ll v, ll col)
{
    ans.push_back(v);
    for (int i = 0; i < f[v].size(); i++)
    {
        ll to = f[v][i];
        if (dp[to][col] > 0)
            dfs2(to, col);
    }
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (i = 1; i <= n; i++)
        for (j = 0; j < 2; j++)
            if (dp[i][j] > m)
            {
                m = dp[i][j];
                l = i;
                r = j;
            }
    cout << m << endl;
    dfs2(l, r);
    cout << ans.size() << endl;
    for (j = 0; j < ans.size(); j++)
        cout << ans[j] << " ";
    return 0;
}