import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.util.List;

public class vowels 

{
public static void main(String[] args) 
{
System.out.print("Hello Folks, \n Please enter a string containing all vowels: \n" );
Scanner sc =new Scanner(System.in);
String akki = sc.next();
System.out.println(MagicalSequence(akki));
}
static int MagicalSequence(String s) 
{
		if (s.length() == 0 || s.length() == 1) 
{
		return s.length();
}
		List<Character> v = Arrays.asList(new Character[] { 'a', 'e', 'i', 'o', 'u' });
		int r = 0;
		char[] ar = s.toCharArray();
		int c[] = new int[ar.length];
		c[0] = 1;
		for (int i = 1; i < ar.length; i++) {
			int max = -1;
			for (int j = 0; j < i; j++) {
				int diff = v.indexOf(ar[i]) - v.indexOf(ar[j]);
				if (c[j] > max && (diff == 0 || diff == 1)) {
					max = c[j];
				}
			}
			c[i] = 1 + max;
		}
		for (int i = 0; i < c.length; i++) {
			if (r < c[i] && ar[i] == 'u') {
				r = c[i];
			}
		}
		return r;
	}
	static int MagicalSequenceA(String s) {
		int r = 0;
		char c[] = s.toCharArray();
		char v[]={'a','e','i','o','u'};
		int j=0;
		for (int i = 0; i < c.length; i++) 
{
			if (c[i]==v[j]) 
{
				r++;
			} 
else if (c[i]>=v[j]) 
{
				r++;
				j++;
}
}
int r1=0;
 j=0;
		for (int i = 0; i < c.length; )
 {
			if (c[i]==v[j]) 
{
				r1++;
}
			int ti=s.indexOf(v[j], i+1);	
			if (ti!=-1) 
{
				i=ti;			
			}
else
{
i++;
	j++;
	}
	}
		if (r1>r)
 {
		r=r1;
	}
		if (j<=4) {
		return 0;
		}
		return r;
	}
	static int MagicalSequenceB(String s) 
  {
	int r = 0;
	char c[] = s.toCharArray();
   char v[]={'a','e','i','o','u'};
	int j=0;
	for (int i = 0; i < c.length; i++)
  {
		if (c[i]==v[j]) 
  {
		r++;
	}
     else if (c[i]>=v[j]) {
		r++;
		j++;
		}
		}
		if (j!=4) 
     {
		return 0;
		}
		return r;
	} 
}