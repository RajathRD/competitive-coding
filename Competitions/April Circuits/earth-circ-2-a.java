import java.io.*;
import java.math.*;
import java.util.*;
class permute
{
  public static int count = 0;
  public static int gcd( int a, int b)
  {
    return (b==0)? a: gcd( b , a % b );
  }

  public static BigInteger fun ( String a )
  {
  	int diff;
  //SS	cout<<"1";
  	BigInteger prod = new BigInteger("1");
    int length = a.length();
  	for(int i=2;i<=length-1;i++)
  	{
  		for(int j=0;j<length-i;j++)
  		{
    //    cout<<"Considering "<<a[j]<<" "<<a[j+i]<<endl;
  		//	cout<<"2";
  			diff = Math.abs(a.charAt(j)-a.charAt(j+i));
  			if(	diff	== 1)
  				continue;
  			else
  			{
  			//	cout<<"3";
  //        cout<<diff<<" "<<i<<endl;
          int gcda = gcd( i, diff);
  				prod = prod.multiply(BigInteger.valueOf(gcda));
  			}
  		}
  	}
  //  System.out.println(a+" : "+prod);
   	return prod;
  }
  public static ArrayList<String> permutation(String s) {
      // The result
      ArrayList<String> res = new ArrayList<String>();
      // If input string's length is 1, return {s}
      if (s.length() == 1) {
        {
          System.out.println(++count);
          res.add(s);
        }
      } else if (s.length() > 1) {
          int lastIndex = s.length() - 1;
          // Find out the last character
          String last = s.substring(lastIndex);
          // Rest of the string
          String rest = s.substring(0, lastIndex);
          // Perform permutation on the rest string and
          // merge with the last character
          res = merge(permutation(rest), last);
          
      }
      return res;
  }

  /**
   * @param list a result of permutation, e.g. {"ab", "ba"}
   * @param c    the last character
   * @return     a merged new list, e.g. {"cab", "acb" ... }
   */
  public static ArrayList<String> merge(ArrayList<String> list, String c) {
      ArrayList<String> res = new ArrayList<String>();
      // Loop through all the string in the list
      for (String s : list) {
          // For each string, insert the last character to all possible postions
          // and add them to the new list
          for (int i = 0; i <= s.length(); ++i) {
              String ps = new StringBuffer(s).insert(i, c).toString();
              res.add(ps);

          }
      }
      return res;
  }
  public static void main(String args[])
  {
    ArrayList<String> list = new ArrayList<String>();
    list = permutation("ABCD");
  //  System.out.println(list.size());
    System.out.println("Done permuting");
    BigInteger sum = new BigInteger("0");
    for( String s : list)
    {
    //    System.out.println(s);
        sum = sum.add(fun(s));
    }
    System.out.println(sum);
  }
}
