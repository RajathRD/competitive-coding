#include <iostream>
#include <vector>

using namespace std;

int *counts1;
int *counts2;
vector<int> A;

// returns a pointer to the active array
int *do_it(int N, int M, int s) {
    int *active = counts1;
    int *prev = counts2;
    int *tmp;

    // start by marking S
    prev[s]=1;

    for(int m=0; m<M; m++) {
        int x = A[m];
        for(int i=0; i<N; i++) {
           if(prev[i]!=0) {
                if(i+x < N)
                    active[i+x] = (active[i+x] + prev[i]) % 1000000007;
                if(i-x >= 0)
                    active[i-x] = (active[i-x] + prev[i]) % 1000000007;
                prev[i]=0;
           }
        }

        // swap the arrays
        tmp = active;
        active = prev;
        prev = tmp;
    }

    return prev;
}

int main() {
    int T, tmp;
    cin >> T;

    while(T--) {
        int N, M, s;
        cin >> N >> M >> s;

        A.clear();
        for(int i=0; i<M; i++) {
            cin >> tmp;
            A.push_back(tmp);
        }

        counts1 = new int[N];
        counts2 = new int[N];
        for(int i=0; i<N; i++)
            counts1[i]=counts2[i]=0;

        int *active = do_it(N, M, s-1);

        for(int i=0; i<N; i++) {
            cout << active[i] << ' ';
        }
        cout << endl;

        delete [] counts1;
        delete [] counts2;
    }

    return 0;
}
