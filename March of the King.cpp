#include <stdio.h>
#include <bits/stdtr1c++.h>

#define MOD 88883
#define valid(i, j) ((i) >= 0 && (i) < n && (j) >= 0 && (j) < m)

using namespace std;

const int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

long long num[8][8];
char str[10][10], pattern[20];
int n, m, p, counter[8][8][100010] = {0};
unsigned long long hashmap[8][8][100010] = {0};

inline void add(int i, int j, unsigned long long mask){
    int k = ++mask % MOD;
    while (hashmap[i][j][k] && hashmap[i][j][k] != mask) k++;
    hashmap[i][j][k] = mask, counter[i][j][k]++;
}

inline int get(int i, int j, unsigned long long mask){
    int k = ++mask % MOD;
    while (hashmap[i][j][k] && hashmap[i][j][k] != mask) k++;
    return counter[i][j][k];
}

void insert(int i, int j, int c, int lim, unsigned long long mask){
    if (c > lim){
        add(i, j, 0);
        for (unsigned long long k = mask; k > 0; k = (k - 1) & mask){
            add(i, j, k);
        }
        return;
    }

    int d, k, l;
    for (d = 0; d < 8; d++){
        k = i + dx[d], l = j + dy[d];
        if (valid(k, l) && str[k][l] == pattern[c] && !(mask & num[k][l])){
            insert(k, l, c + 1, lim, mask | num[i][j]);
        }
    }
}

void count(int i, int j, int c, int lim, unsigned long long mask, long long& res){
    if (c < lim){
        res += get(i, j, 0);
        for (unsigned long long k = mask; k > 0; k = (k - 1) & mask){
            if (__builtin_popcountll(k) & 1) res -= get(i, j, k);
            else res += get(i, j, k);
        }
        return;
    }

    int d, k, l;
    for (d = 0; d < 8; d++){
        k = i + dx[d], l = j + dy[d];
        if (valid(k, l) && str[k][l] == pattern[c] && !(mask & num[k][l])){
            count(k, l, c - 1, lim, mask | num[i][j], res);
        }
    }
}

long long solve(){
    int i, j, h = 0, lim = p / 2;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            num[i][j] = 1LL << h++;
        }
    }


    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (str[i][j] == pattern[0]){
                insert(i, j, 1, lim, 0);
            }
        }
    }

    long long res = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (str[i][j] == pattern[p - 1]){
                count(i, j, p - 2, lim, 0, res);
            }
        }
    }
    return res;
}

int main(){
    int i, j, k, l;

    n = 8, m = 8;
    scanf("%d", &p);
    assert(p >= 1 && p <= 11);
    scanf("%s", pattern);
    assert(strlen(pattern) == p);
    for (i = 0; i < p; i++) assert(pattern[i] >= 'a' && pattern[i] <= 'z');

    assert(n == 8 && m == 8);
    for (i = 0; i < n; i++){
        assert(scanf("%s", str[i]) != EOF);
        assert(strlen(str[i]) == m);
        for (j = 0; j < m; j++){
            assert(str[i][j] >= 'a' && str[i][j] <= 'z');
        }
    }

    cout << solve() << endl;
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
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,r,x,y,K,tot,h,H;
long long ans;
string s,t,s1;
char c[10][10];
ll dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
vector<ll> f;
ll used[10][10];
struct HashSet {
    ll keys[1200000], values[1200000];
    ll getHash(ll x)
    {
        return (x&524287);
    }
    HashSet()
    {
        for (int i = 0; i < 1200000; i++)
            keys[i] = -1;
    }
    ll get(ll x)
    {
        ll val = getHash(x);
        while (keys[val] != x && keys[val] != -1)
            val++;
        if (keys[val] == x)
            return values[val];
        return 0;
    }
    void add(ll x)
    {
        ll val = getHash(x);
        while (keys[val] != x && keys[val] != -1)
            val++;
        if (keys[val] == -1)
            values[val] = 0;
        keys[val] = x;
        values[val]++;
    }
} F[6];
bool in_range(ll x, ll y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
void make_moves1(ll x, ll y, string s)
{
    ll sz = s.size();
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            used[i][j] = 0;
    f.clear();
    for (int mask = 0; mask < (1<<(3*sz)); mask++)
    {
        ll cur = mask;
        ll cur_x = x, cur_y = y;
        used[cur_x][cur_y] = mask+1;
        ll j;
        for (j = 0; j < sz; j++)
        {
            cur_x += dir[cur&7][0];
            cur_y += dir[cur&7][1];
            cur >>= 3;
            if (!in_range(cur_x, cur_y) || c[cur_x][cur_y] != s[j] || used[cur_x][cur_y] == mask+1)
                break;
            used[cur_x][cur_y] = mask+1;
        }
        if (j == sz)
        {
            f.push_back(mask);
        }
    }
    tot = f.size();
    for (int i = 0; i < f.size(); i++)
    {
        ll mask = f[i];
        ll cur_x = x, cur_y = y;
        int g[6];
        for (j = 0; j < sz; j++)
        {
            cur_x += dir[mask&7][0];
            cur_y += dir[mask&7][1];
            g[j] = cur_x*8+cur_y;
            mask >>= 3;
        }
        for (j = 1; j < (1<<sz); j++)
        {
            int G[6];
            ll Gsz = 0;
            for (k = 0; k < sz; k++)
                if ((j&(1<<k)) != 0)
                    G[Gsz++] = g[k];
            sort(G, G+Gsz);
            ll tmp = 0;
            for (k = 0; k < Gsz; k++)
                tmp = tmp*64 + G[k];
            F[Gsz].add(tmp);
        }
    }
}

void make_moves2(ll x, ll y, string s)
{
    ll sz = s.size();
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            used[i][j] = 0;
    f.clear();
    for (int mask = 0; mask < (1<<(3*sz)); mask++)
    {
        ll cur = mask;
        ll cur_x = x, cur_y = y;
        used[cur_x][cur_y] = mask+1;
        ll j;
        for (j = 0; j < sz; j++)
        {
            cur_x += dir[cur&7][0];
            cur_y += dir[cur&7][1];
            cur >>= 3;
            if (!in_range(cur_x, cur_y) || c[cur_x][cur_y] != s[j] || used[cur_x][cur_y] == mask+1)
                break;
            used[cur_x][cur_y] = mask+1;
        }
        if (j == sz)
            f.push_back(mask);
    }
    for (int i = 0; i < f.size(); i++)
    {
        ll mask = f[i];
        ll cur_x = x, cur_y = y;
        vector<ll> g;
        for (j = 0; j < sz; j++)
        {
            cur_x += dir[mask&7][0];
            cur_y += dir[mask&7][1];
            g.push_back(cur_x*8+cur_y);
            mask >>= 3;
        }

        ans += tot;
        for (j = 1; j < (1<<sz); j++)
        {
            ll G[6];
            ll Gsz = 0;
            for (k = 0; k < sz; k++)
                if ((j&(1<<k)) != 0)
                    G[Gsz++] = g[k];
            sort(G, G+Gsz);
            ll tmp = 0;
            for (k = 0; k < Gsz; k++)
                tmp = tmp*64 + G[k];
            ll flag;
            if (Gsz%2)
                flag = -1;
            else
                flag = 1;
            //cout << ssss << " " << tmp << " " << tot << endl;
            ans += flag*F[Gsz].get(tmp);
            //cout << ans << endl;
        }
    }

}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    cin >> s;
    for (i = 0; i < 8; i++)
    {
        scanf("%s", c[i]);
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            ll mid = n/2;
            if (c[i][j] != s[mid])
                continue;
            string t = s.substr(mid+1);
            make_moves1(i, j, t);
            t = s.substr(0, mid);
            reverse(t.begin(), t.end());
            make_moves2(i, j, t);
            for (k = 0; k < 600000; k++)
                for (int jj = 1; jj < 6; jj++)
                    F[jj].keys[k] = -1;
        }
    cout << ans << endl;
    return 0;
}