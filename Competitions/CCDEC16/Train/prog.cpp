#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while ( T-- )
	{
		int N;
		cin >> N;

		int div = N/8;
    N %= 8;

		if ( N == 7 )
			N = 8;
		else if ( N == 8 || N == 0 )
		{
      N = 7;
      div --;
    }
		else if( N + 3 > 6 )
			N -= 3;
		else
			N += 3;

		string ans[8] = {"LB","MB","UB","LB","MB","UB","SL","SU"};

		cout << 8*div+N << ans[N-1] << endl;
	}
	return 0;
}
