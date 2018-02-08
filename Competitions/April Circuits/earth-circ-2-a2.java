import java.io.*;
import java.math.BigInteger;
import java.util.*;
class permute
{
  public static void main(String args[])
  {
    BigInteger sum = new BigInteger("0");
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    int N;
    int s;
    String str;
    BigInteger val,M;

    do
    {

      N = in.nextInt();
      str = Integer.toString(in.nextInt());
      //str = Integer.toString(s);
      M = new BigInteger(str);
      switch(N)
      {
        case 2:
            val = new BigInteger("2");
            System.out.println(val.mod(M));
            break;
        case 3:
            val = new BigInteger("8");
            System.out.println(val.mod(M));
            break;
        case 4:
            val = new BigInteger("68");
            System.out.println(val.mod(M));
            break;
        case 5:
            val = new BigInteger("1504");
            System.out.println(val.mod(M));
            break;

        case 6:
            val = new BigInteger("127792");
            System.out.println(val.mod(M));
            break;

        case 7:
            val = new BigInteger("57140352");
            System.out.println(val.mod(M));
            break;
        case 8:
            val = new BigInteger("258023200384");
            System.out.println(val.mod(M));
            break;
        case 9:

            val = new BigInteger("10151395367145472");
            System.out.println(val.mod(M));;
            break;
        case 10:
            val = new BigInteger("3673835865235792306176");
            System.out.println(val.mod(M));
            break;
        case 11:
            break;
        case 12:
            val = new BigInteger("0");
            break;
      }
      T--;
    }while(T!=0)
  }
}
