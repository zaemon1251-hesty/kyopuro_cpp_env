#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

void dgemm (int n, double *A, double *B, double *C) {
    for (int i = 0; i < n; i++)
	    for (int j = 0; i < n; j++)
		{
			double cij = C[i+j*n];
			for (int k = 0, k < n, k++ )
			{
				cij += A[i+k*n] * B[k+j*n];
			}
			C[i+j*k] = cij;
		}
}

int main() {
	int N = 10;
	int A[N][N], B[N][N], C[N][N];
    return 0;
}
