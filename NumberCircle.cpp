#include <cstdio>
#include <vector>
#include <algorithm>
void multiply(int a[3][3], int b[3][3])
{
    // Creating an auxiliary matrix to store elements
    // of the multiplication matrix
    int mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    // storing the multiplication result in a[][]
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}
int main(){

    long n; scanf("%ld", &n);
    std::vector<long> a(n); for(long p = 0; p < n; p++){scanf("%ld", &a[p]);}
    sort(a.begin(), a.end());
    if(a[n - 1] >= a[n - 2] + a[n - 3]){puts("NO");}
    else{
        long temp = a[n - 2]; a[n - 2] = a[n - 1]; a[n - 1] = temp;
        puts("YES");
        for(long p = 0; p < n; p++){printf("%ld ", a[p]);}
        puts("");
    }

    return 0;
}
