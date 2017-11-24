import java.util.*;
import java.io.*;

public class solver
{
	static int[][] array;
	static int n;
	static char wind;
	static int count = 1;
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringBuffer str = new StringBuffer();
		String line = br.readLine();
		
		
		n = Integer.parseInt(line);
		
		array = new int[n][n];
		
		line = br.readLine();
		
		wind = line.charAt(0);
		
		line = br.readLine();
		
		StringTokenizer sTok = new StringTokenizer(line);
		
		int x = Integer.parseInt(sTok.nextToken());
		int y = Integer.parseInt(sTok.nextToken());
		
		rec(x,y);
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				str.append(array[i][j] + " ");
			}
			str.append("\n");
		}
		
		out.write(str.toString());
		out.flush();
	}
	
	public static void rec(int x, int y)
	{
		array[x][y] = count;
		count++;
		
		if(wind == 'n')
		{
			if(x-1 >= 0 && array[x-1][y] == 0)
			{
				rec(x-1,y);
			}
			else if(y-1 >= 0 && array[x][y-1] == 0)
			{
				rec(x,y-1);
			}
			else if(y+1 < n && array[x][y+1] == 0)
			{
				rec(x,y+1);
			}
			else if(x+1 < n && array[x+1][y] == 0)
			{
				rec(x+1,y);
			}
		}
		else if(wind == 's')
		{
			if(x+1 < n && array[x+1][y] == 0)
			{
				rec(x+1,y);
			}
			else if(y-1 >= 0 && array[x][y-1] == 0)
			{
				rec(x,y-1);
			}
			else if(y+1 < n && array[x][y+1] == 0)
			{
				rec(x,y+1);
			}
			else if(x-1 >= 0 && array[x-1][y] == 0)
			{
				rec(x-1,y);
			}
		}
		else if(wind == 'e')
		{
			if(y+1 < n && array[x][y+1] == 0)
			{
				rec(x,y+1);
			}
			else if(x-1 >= 0 && array[x-1][y] == 0)
			{
				rec(x-1,y);
			}
			else if(x+1 < n && array[x+1][y] == 0)
			{
				rec(x+1,y);
			}
			else if(y-1 >= 0 && array[x][y-1] == 0)
			{
				rec(x,y-1);
			}
		}
		else if(wind == 'w')
		{
			if(y-1 >= 0 && array[x][y-1] == 0)
			{
				rec(x,y-1);
			}
			else if(x-1 >= 0 && array[x-1][y] == 0)
			{
				rec(x-1,y);
			}
			else if(x+1 < n && array[x+1][y] == 0)
			{
				rec(x+1,y);
			}
			else if(y+1 < n && array[x][y+1] == 0)
			{
				rec(x,y+1);
			}
		}
	}
}