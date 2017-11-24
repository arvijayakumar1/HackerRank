#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<map>
#define ll long long
using namespace std;
char c;
inline void read(ll &a)
{
	a=0;do c=getchar();while(c<'0'||c>'9');
	while(c<='9'&&c>='0')a=(a<<3)+(a<<1)+c-'0',c=getchar();
}
inline void read(int &a)
{
	a=0;do c=getchar();while(c<'0'||c>'9');
	while(c<='9'&&c>='0')a=(a<<3)+(a<<1)+c-'0',c=getchar();
}
int Bg[120001],Ed[120001];
int U[240001],dfn;
inline ll Pow(ll x)
{
	return x*(x-1)/2;
}
namespace Seg
{
	const
		int	Node_MAXN=1e6+1;
	ll Cache=0;
	struct Node
	{
		Node *lc,*rc;
		int Min,Sum;
		int l,r;
	}*Node_Cache;
	inline int min(int a,int b){return a>b?b:a;}
	inline Node *New()
	{
		Node *R;
		if(!Cache)
			Node_Cache=new Node[Cache=Node_MAXN];
		R=Node_Cache+(--Cache);
		R->lc=R->rc=NULL;
		R->Min=R->Sum=R->l=R->r=0;
		return R;
	}
	inline void Up(Node *a)
	{
		if(a->lc==NULL)return;
		a->Sum=a->lc->Sum+a->rc->Sum;
		a->Min=min(a->lc->Min,a->lc->Sum+a->rc->Min);
	}
	
	ll Query_Sum(Node *Cur,ll l,ll r)
	{
		if(!Cur)return 0;
		if(Cur->l>=l&&Cur->r<=r)return Cur->Sum;
		ll R=0;
		if(Cur->lc&&Cur->lc->r>=l)
			R+=Query_Sum(Cur->lc,l,r);	
		if(Cur->rc&&Cur->rc->l<=r)
			R+=Query_Sum(Cur->rc,l,r);
		return R;
	}
	void Down(Node *Cur,ll &Ans,ll CurSum)
	{
		if(CurSum<0)
			CurSum++,CurSum--;
		if(!Cur)return void(Ans=-1);
		if(Cur->l==Cur->r)
		{
			return void(Ans=Cur->l);
		}
		if(Cur->lc->Min+CurSum<=0)
			return Down(Cur->lc,Ans,CurSum);
		return Down(Cur->rc,Ans,CurSum+Cur->lc->Sum);
	}
	
	void Query_Min(Node *Cur,ll l,ll &Ans,ll &CurSum)
	{
		if(!Cur)return ;
		if(Cur->l==Cur->r)
			return void(CurSum+=Cur->Sum);
		if(!Cur->lc)
			return ;
		if(Cur->lc->r>=l)
		{
			Query_Min(Cur->lc,l,Ans,CurSum);
			if(Ans)return;
			if(Cur->rc->Min+CurSum<=0)
				return Down(Cur->rc,Ans,CurSum);
			CurSum+=Cur->rc->Sum;
			return ;
		}		
		Query_Min(Cur->rc,l,Ans,CurSum);
	}

	ll Query(Node *Cur,ll u)
	{
		ll F=0,S=0;
		Query_Min(Cur,Bg[u],F,S);
		F=U[F];
		return Pow(Query_Sum(Cur,Bg[F],Ed[F]-1));
	}

	void Modify(Node *Cur,ll l,ll data)
	{
		if(Cur->l==Cur->r)
			{Cur->Min+=data,Cur->Sum+=data;return;}
		if(!Cur->lc)
			Cur->lc=New(),Cur->rc=New(),
			Cur->lc->l=Cur->l,Cur->rc->r=Cur->r,Cur->rc->l=(Cur->lc->r=Cur->l+Cur->r>>1)+1;
		ll mid=Cur->lc->r;
		l<=mid?Modify(Cur->lc,l,data):Modify(Cur->rc,l,data);
		Up(Cur);
	}

	void Erase(Node *Cur,ll u,ll f,ll &Sum)
	{
		ll hu=Query_Sum(Cur,Bg[u],Bg[u]);
		ll hf=Query_Sum(Cur,Bg[f],Bg[f]);
		if(!hu||!hf)
			puts("No Such Edge");
		ll F=0,S=0;
		Query_Min(Cur,Bg[u],F,S);
		F=U[F];
		
		S=Query_Sum(Cur,Bg[u],Ed[u]-1);
		//Sum+=S*(S-1)/2;
		Sum+=Pow(S);
		ll S2=Query_Sum(Cur,Bg[F],Ed[F]-1);
		
		//Sum-=S2*(S2-1)/2;
		Sum-=Pow(S2);
		S2-=S;
		//Sum+=S2*(S2-1)/2;
		Sum+=Pow(S2);
		Modify(Cur,Ed[F],S);
		Modify(Cur,Ed[u],-S);
	}
		
	void Insert(Node *Cur,ll u,ll f,ll &Sum)
	{
		ll hu=Query_Sum(Cur,Bg[u],Bg[u]);
		ll hf=Query_Sum(Cur,Bg[f],Bg[f]);
		if(!hu)
			Modify(Cur,Bg[u],1),
			Modify(Cur,Ed[u],-1);
		if(!hf)
			Modify(Cur,Bg[f],1),
			Modify(Cur,Ed[f],-1);
		
		ll F=0,s=0;
		Query_Min(Cur,Bg[f],F,s);

		F=U[F];
			
		ll S=Query_Sum(Cur,Bg[u],Ed[u]-1);
		//Sum-=S*(S-1)/2;
		Sum-=Pow(S);	
		ll S2=Query_Sum(Cur,Bg[F],Ed[F]-1);
		//Sum-=S2*(S2-1)/2;
		Sum-=Pow(S2);	
		Modify(Cur,Ed[u],S);
		Modify(Cur,Ed[F],-S);	
		S2+=S;
		//Sum+=S2*(S2-1)/2;
		Sum+=Pow(S2);
	}	
}
struct Mode
{
	int l,r;
	ll sum,data;
	Seg::Node*Rt;
}T[2097153];
void Up(ll place){T[place].sum=T[place<<1].sum+T[place<<1|1].sum;}
ll Query(int place,int l,int r)
{
	ll S=0;
	if(T[place].l>=l&&T[place].r<=r)return T[place].sum;
	int mid=T[place<<1].r;
	if(mid>=l)
		S+=Query(place<<1,l,r);
	if(mid<r)
		S+=Query(place<<1|1,l,r);
	return S;
}

ll Query_S(ll place,ll l,ll data)
{
	if(T[place].l==T[place].r)return Seg::Query(T[place].Rt,data);
	ll mid=T[place<<1].r;
	if(l<=mid)
		return Query_S(place<<1,l,data);
	return Query_S(place<<1|1,l,data);
}

void Add(ll place,ll l,ll u,ll f)
{
	if(T[place].l==T[place].r)
	{
		Seg::Node *&Rt=T[place].Rt;
		if(!Rt)
			Rt=Seg::New();
		Rt->l=1,Rt->r=dfn;
		Seg::Insert(Rt,u,f,T[place].data);
		T[place].sum=T[place].data;
		return ;
	}
	ll mid=T[place<<1].r;
	if(mid>=l)
		Add(place<<1,l,u,f);
	else Add(place<<1|1,l,u,f);
	Up(place);
}

void Delete(ll place,ll l,ll u,ll f)
{
	if(T[place].l==T[place].r)
	{
		Seg::Node *&Rt=T[place].Rt;
		if(!Rt)
			puts("No Such Seg"),Rt=Seg::New();
		Rt->l=1,Rt->r=dfn;
		Seg::Erase(Rt,u,f,T[place].data);
		T[place].sum=T[place].data;
		return ;
	}
	ll mid=T[place<<1].r;
	if(mid>=l)
		Delete(place<<1,l,u,f);
	else Delete(place<<1|1,l,u,f);
	Up(place);
}
void Build(ll place,ll l,ll r)
{
	T[place].l=l,T[place].r=r;
	if(l^r)
		Build(place<<1,l,l+r>>1),Build(place<<1|1,(l+r>>1)+1,r);

}
struct Chain
{
	Chain*next;
	int u;
}*Head[360001];
int X[360001],Y[360001],W[360001];
void Add(ll u,ll v)
{
	Chain*tp=new Chain;tp->u=v;tp->next=Head[u];Head[u]=tp;
}

void dfs(ll u,ll f)
{
	U[Bg[u]=++dfn]=u;
	for(Chain*tp=Head[u];tp;tp=tp->next)
	if(tp->u^f)
		dfs(tp->u,u);
	U[Ed[u]=++dfn]=u;
}

int main()
{

	ll n;
	read(n);
	for(ll i=1;i<n;i++)
	{
		ll u,v,l;
		read(X[i]),read(Y[i]),read(W[i]);
		Add(X[i],Y[i]);
		Add(Y[i],X[i]);
	}
	dfs(1,1);
	Build(1,1,1e6);
	for(ll i=1;i<n;i++)
	{
		if(Bg[X[i]]<Bg[Y[i]])
			swap(X[i],Y[i]);
		Add(1,W[i],X[i],Y[i]);
	}
	
	ll S=T[1].sum;
	//printf("%lld\n",S);
	
	ll Q;
	read(Q);
	for(ll i=1;i<=Q;i++)
	{
		ll x;
		int op;
		read(op);
		if(op==1)
		{
			read(x);
			Delete(1,W[x],X[x],Y[x]);
			read(W[x]);
			Add(1,W[x],X[x],Y[x]);
		}
		else if(op==2)
		{
			int l,r;
			read(l),read(r);
			ll S=Query(1,l,r);
			printf("%lld\n",S);
		}
		else if(op==3)
		{
			read(x);
			ll P=Query_S(1,W[x],X[x]);
			printf("%lld\n",P);
		}
	}
	return 0;
}







#include <bits/stdc++.h>
using namespace std;

#define K 18
#define N 121111

typedef long long ll;

template <class T>
struct Fenwick {
    int n;
    T *a;
    Fenwick(int n): Fenwick(n, new T[n+1]) {}
    Fenwick(int n, T *a): n(n), a(a) {
        for (int i = 0; i <= n; i++) a[i] = 0;
    }

    inline void inc(int i, T v) {
        for (i++; i <= n; i += i & -i) a[i] += v;
    }

    inline T presum(int i) {
        T s = 0;
        for (; i; i ^= i & -i) s += a[i];
        return s;
    }

    inline T sum(int i, int j) {
        return presum(j) - presum(i);
    }
};

typedef pair<int,int> edge;

int parent[N];
int enode[N];
vector<pair<int,int>> adj[N];
int prei[N];
int prej[N];
int anc[K][N];
Fenwick<int> sizes(N);
Fenwick<int> detached(N);

inline void _ainc(int i, int v) {
    detached.inc(prej[i], -v);
    detached.inc(prei[i], +v);
}

#define _atop(i) detached.presum(prei[i] + 1)
#define _attach(i) _ainc((i), -1)
#define _detach(i) _ainc((i), +1)

inline int _find(int i) {
    int target = _atop(i);
    for (int k = K; k--;) {
        int j = anc[k][i];
        if (i != j && target == _atop(j)) {
            i = j;
        }
    }
    return i;
}

inline int _sum(int i) {
    return sizes.sum(prei[i], prej[i]) + 1;
}

inline void _inc(int i, int v) {
    if (i) sizes.inc(prei[parent[i]], v);
}

inline ll remove(int x) {
    int i = enode[x];
    _detach(i);
    int j = _find(parent[i]);
    int s1 = _sum(i);
    _inc(i, -s1);
    _inc(j, +s1);
    int s2 = _sum(j);
    return (ll)s1 * s2;
}

inline ll add(int x) {
    int i = enode[x];
    _attach(i);
    int j = _find(parent[i]);
    int s1 = _sum(i);
    int s2 = _sum(j);
    _inc(i, +s1);
    _inc(j, -s1);
    return (ll)s1 * s2;
}

inline ll ask(int i) {
    ll s = _sum(_find(i));
    return s * (s - 1) / 2;
}

int st[N];
int pre[N];
void conn(int n, edge *edges) {
    for (int i = 0; i < n; i++) parent[i] = -1;

    for (int idx = 0; idx < n-1; idx++) {
        int i = edges[idx].first;
        int j = edges[idx].second;
        adj[i].push_back(make_pair(j, idx));
        adj[j].push_back(make_pair(i, idx));
    }

    parent[0] = 0;
    int sc = 0;
    st[sc++] = 0;
    for (int t = 0; sc; t++) {
        int i = pre[t] = st[--sc];
        for (pair<int,int> p : adj[i]) {
            int j = p.first;
            if (parent[j] == -1) {
                parent[j] = i;
                enode[p.second] = j;
                st[sc++] = j;
            }
        }
    }

    for (int idx = n; idx--;) {
        int i = pre[idx];
        prej[i] = prei[i] = idx;
    }

    for (int idx = n; idx--;) {
        int i = pre[idx];
        int p = parent[i];
        prej[p] = max(prej[p], prej[i]++);
    }

    for (int i = 0; i < n; i++) anc[0][i] = parent[i];
    for (int k = 0; k < K-1; k++) {
        for (int i = 0; i < n; i++) {
            anc[k+1][i] = anc[k][anc[k][i]];
        }
    }

    for (int i = 0; i < n; i++) _ainc(i, 1);
}


struct query {
    int tm, t, x;
    query(int tm, int t, int x): tm(tm), t(t), x(x) {}
};

struct squery {
    int tm, t;
    ll a, b;
    squery(int tm, int t, ll a, ll b): tm(tm), t(t), a(a), b(b) {}
    bool operator<(squery& o) {
        return tm < o.tm;
    }
};

map<ll,vector<query>> qlists;
int indices[N];
ll ans[N];
ll colors[N];
edge edges[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int ee = 0; ee < n-1; ee++) {
        int i, j;
        scanf("%d%d%lld", &i, &j, &colors[ee]);
        edges[ee] = edge(i-1, j-1);
    }
    int q;
    scanf("%d", &q);

    vector<squery> seq;
    for (int i = 0; i < q; i++) indices[i] = -1;

    for (int x = 0; x < n-1; x++) {
        qlists[colors[x]].push_back(query(-1, 1, x));
    }

    int ansc = 0;
    for (int tm = 0; tm < q; tm++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            ll v;
            scanf("%d%lld", &x, &v);
            if (colors[--x] != v) {
                qlists[colors[x]].push_back(query(tm, 0, x));
                colors[x] = v;
                qlists[colors[x]].push_back(query(tm, 1, x));
            }
        }
        if (t == 2) {
            ll l, r;
            scanf("%lld%lld", &l, &r);
            qlists[l].size(); qlists[r].size();
            seq.push_back(squery(tm, 2, l, r));
            indices[tm] = ansc++;
        }
        if (t == 3) {
            int x;
            scanf("%d", &x);
            x--;
            qlists[colors[x]].push_back(query(tm, 2, x));
            indices[tm] = ansc++;
        }
    }

    for (int x = 0; x < n-1; x++) {
        qlists[colors[x]].push_back(query(q, 0, x));
    }

    conn(n, edges);
    for (auto it : qlists) {
        int c = it.first;
        for (query que : it.second) {
            if (que.t == 0) seq.push_back(squery(que.tm, 1, c, -remove(que.x)));
            if (que.t == 1) seq.push_back(squery(que.tm, 1, c, +add(que.x)));
            if (que.t == 2) ans[indices[que.tm]] = ask(edges[que.x].first);
        }
    }

    map<ll,int> coli;
    int idx = 0;
    for (auto it : qlists) coli[it.first] = idx++;
    Fenwick<ll> vals(coli.size());
    sort(seq.begin(), seq.end());
    for (squery sque : seq) {
        if (sque.t == 1) vals.inc(coli[sque.a], sque.b);
        if (sque.t == 2) ans[indices[sque.tm]] = vals.sum(coli[sque.a], coli[sque.b] + 1);
    }

    for (int i = 0; i < ansc; i++) printf("%lld\n", ans[i]);
}