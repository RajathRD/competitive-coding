// Java program to find large factorials using BigInteger
import java.math.BigInteger;
import java.util.Scanner;

class Factorial
{
	// Returns Factorial of N
	static BigInteger factorial(int N)
	{
		// Initialize result
		BigInteger f = new BigInteger("1"); // Or BigInteger.ONE

		// Multiply f with 2, 3, ...N
		for (int i = 2; i <= N; i++)
			f = f.multiply(BigInteger.valueOf(i));

		return f;
	}

	// Driver method
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(System.in);
		int T,N;
		T = in.nextInt();
		while(T > 0)
		{
			T--;
			N = in.nextInt();
			System.out.println(factorial(N));
		}
	}
}
