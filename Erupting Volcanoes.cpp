import java.util.*;
import java.io.*;

public class solver
{
	static int n;
	static long[][] array;
	static long[][] used;
	static Queue<Triple> q = new LinkedList<Triple>();
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuffer str = new StringBuffer();
		String line = br.readLine();
		
		n = Integer.parseInt(line);
		
		array = new long[n][n];
		
		line = br.readLine();
		
		int m = Integer.parseInt(line);
		
		for(int i = 0; i < m; i++)
		{
			line = br.readLine();
			StringTokenizer sTok = new StringTokenizer(line);
			
			used = new long[n][n];
			
			int x = Integer.parseInt(sTok.nextToken());
			int y = Integer.parseInt(sTok.nextToken());
			int w = Integer.parseInt(sTok.nextToken());
			
			q.add(new Triple(x,y,w));
			
			process();
		}
		
		/*for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				System.out.print(array[i][j] + " ");
			}
			System.out.println();
		}*/
		
		long max = 0;
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(array[i][j] > max)
					max = array[i][j];
			}
		}
		
		str.append(max);
		
		out.write(str.toString());
		out.flush();
	}
	
	public static void process()
	{
		while(!q.isEmpty())
		{
			Triple t = q.remove();
			
			int x = t.x;
			int y = t.y;
			int z = t.w;
			
			if(z == 0)
			{
				continue;
			}
			
			if(x < 0 || y < 0 || x >= n || y >= n)
				continue;
			
			if(used[x][y] == 1)
			{
				continue;
			}
			
			array[x][y] = array[x][y] + z;
			used[x][y] = 1;
			
			q.add(new Triple(x+1,y+1,z-1));
			q.add(new Triple(x-1,y-1,z-1));
			q.add(new Triple(x+1,y-1,z-1));
			q.add(new Triple(x-1,y+1,z-1));
			q.add(new Triple(x+1,y,z-1));
			q.add(new Triple(x-1,y,z-1));
			q.add(new Triple(x,y+1,z-1));
			q.add(new Triple(x,y-1,z-1));
			
		}
		
	}
	
}

class Triple
{
	int x;
	int y;
	int w;
	
	Triple(int a, int b, int c)
	{
		this.x = a;
		this.y = b;
		this.w = c;
	}
}



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

typedef long long ll;
const int INF = 1e9;

const int MINN = 5;
const int MAXN = 300;
const int MINM = 1;
const int MAXM = 300;
const int MINW = 1;
const int MAXW = 100;

#define assertRange(v,a,b) assert(a <= v && v <= b)

int c[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    assertRange(n, MINN, MAXN);
    int m;
    cin >> m;
    assertRange(m, MINM, MAXM);
    for (int ii = 0; ii < m; ++ii) {
        int x, y, w;
        cin >> x >> y >> w;
        assertRange(x, 0, n-1);
        assertRange(y, 0, n-1);
        assertRange(w, MINW, MAXW);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int dx = abs(i-x);
                int dy = abs(j-y);
                int d = max(dx, dy);
                c[i][j] += max(0, w-d);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res = max(res, c[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}