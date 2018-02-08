import java.util.Scanner;

class SAP1 {
    public static void main(String args[] ) throws Exception {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while( T > 0 )
		{
      T--;
			int N = in.nextInt();
			int a[] = new int[N];
			for(int i=0; i<N; i++)
			{
				a[i] = in.nextInt();
			}
      int count = 1;
      int total = 0;
      for(int i=1; i<N; i++)
      {
        if( a[i] == a[i-1] )
          count++;
        else
        {
          total += (count*(count+1))/2;
          count = 1;
        }
      }
      total += (count*(count+1))/2;
      System.out.println(total);
		}

    }
}
