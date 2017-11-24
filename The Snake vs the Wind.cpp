#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
const int INF = 1e9;

const int N = 60;
int visited[N][N];

map<char, vector<pii>> dirs;

int n;
char wind;

void dfs(int x, int y, int t) {
    visited[x][y] = t;
    for (auto p : dirs[wind]) {
        int nx = x+p.fi;
        int ny = y+p.se;
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
            dfs(nx, ny, t+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    assert(n >= 2 && n <= 60);
    cin >> wind;
    assert(wind == 'n' || wind == 'e' || wind =='s' || wind == 'w');
    int x, y; 
    cin >> x >> y;
    assert((x == 0 && y == 0) ||
           (x == 0 && y == n-1) ||
           (x == n-1 && y == 0) ||
           (x == n-1 && y == n-1));

    dirs['n'] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    dirs['e'] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    dirs['s'] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    dirs['w'] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    dfs(x, y, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}