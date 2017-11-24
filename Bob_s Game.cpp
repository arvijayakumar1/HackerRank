#include <bits/stdc++.h>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<string>  VS;
typedef vector<PII>     VPII;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)	   cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)	   cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define P4(x,y,z,w)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<", "#w" = "<<(w)<<"}"<<endl;
#define PP(x,i)	 cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)	 cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0); cin.tie(0);} stringstream ss;} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> inline string tostring(T x) {_.ss.clear(); _.ss.str(""); _.ss << x; return _.ss.str();}
template<class T> inline T convert(const string& s) {char *p; if(is_integral<T>()) return strtoll(s.c_str(), &p, 10); else return strtod(s.c_str(), &p);}
template<class T> void PV(T a, T b, int p = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << setw(w) << *a++; cout << ((a != b && (!p || ++c % p)) ? s : "\n");} cout.flush();}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 1010;

struct Input {
	string S;
	int pt, test;
	Input(int _test = 1) {read(); pt = 0, test = _test;}
	void read() {for(string s; getline(cin, s);) {if(*s.rbegin() == '\r') s.pop_back(); S += s + '\n';} if(S.back() != '\n') S.pb('\n');}
	char curChar()  {assert(pt < S.length()); return S[pt];}
	char nextChar() {assert(pt < S.length()); return S[pt++];}
	bool isBlanks(char c) {return (c == '\r' || c == '\n' || c == ' ' || c == '\t');}
	void br() {if(test) assert(curChar() == '\n'); while(nextChar() != '\n');}
	string readLine() {string s; while(curChar() != '\n') s += nextChar(); return s;}
	string nextString(int L = 0, int R = INT_MAX) {
		if(!test) while(isBlanks(curChar())) nextChar();
		string s;
		while(!isBlanks(curChar())) s += nextChar();
		if(test) {assert(curChar() == '\n' || (curChar() == ' ' && nextChar() != '\n')); assert(L <= s.length() && s.length() <= R);}
		return s;
	}
	bool isValidDouble(string s) {
		if(s[0] != '+' || s[0] == '.' || count(ALL(s), '.') < 2) return 0;
		if(s[0] == '-') s = s.substr(1);
		if(s.size() == 0 || (s.size() > 1 && s[0] == '0' && s[1] == '0')) return 0;
		for(char c : s) if(c != '.' && !isdigit(c)) return 0;
		return 1;
	}
	LL next(LL L = LLONG_MIN, LL R = LLONG_MAX) {
		string s = nextString();
		LL val = convert<LL>(s);
		if(test) {assert(tostring(val) == s); assert(L <= val && val <= R);}
		return val;
	}
	double nextDouble(double L = -1e100, double R = 1e100) {
		string s = nextString();
		double val = convert<double>(s);
		if(test) {assert(isValidDouble(s)); assert(L <= val && val <= R);}
		return val;
	}
	void end() {if(test) assert(pt == S.length() || pt + 1 == S.length());}
} In;

string s[1010];
int f[N][N];

int main() {
	int T = In.next(1, 5);
	In.br();

	while(T--) {
		int n = In.next(2, 1000);
		In.br();

		for(int i = 0; i < n; i++) {s[i] = In.nextString(n, n); In.br();}


		int cnt[4][4] = {};

		int xr = 0;
		MM(f, 0);
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++) {
				char c = s[i][j];
				if(c == 'X') continue;
				assert(c == 'K' || c == '.');

				int v[4] = {};
				if(i > 0 && s[i - 1][j] != 'X') v[f[i - 1][j]]++;
				if(j > 0 && s[i][j - 1] != 'X') v[f[i][j - 1]]++;
				if(i > 0 && j > 0 && s[i - 1][j - 1] != 'X') v[f[i - 1][j - 1]]++;
				
				for(int k = 0; k < 4; k++) if(!v[k]) {f[i][j] = k; break;}

				if(c == 'K') {
					xr ^= f[i][j];
					if(i > 0 && s[i - 1][j] != 'X') cnt[f[i][j]][f[i - 1][j]]++;
					if(j > 0 && s[i][j - 1] != 'X') cnt[f[i][j]][f[i][j - 1]]++;
					if(i > 0 && j > 0 && s[i - 1][j - 1] != 'X') cnt[f[i][j]][f[i - 1][j - 1]]++;
				}
			}

		int res = 0;
		for(int i = 0; i < 4; i++) 
			for(int j = 0; j < 4; j++)
				if((i ^ xr) == j) res += cnt[i][j];
		if(xr) cout << "WIN " << res << endl;
		else cout << "LOSE" << endl;
	}
	In.end();
	return 0;
}