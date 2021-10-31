#include<iostream>
#include<math.h>
using namespace std;

int binary_2_decimal(int n){
    int last_digit, decimal = 0;
    for (int i = 0; n > 0; i++)
    {
        last_digit = n % 10;

        decimal += last_digit * pow(2, i);

        n = n / 10;
    }
    return decimal ;
}

int main(){
    int n;
    cin>> n;

    cout<< binary_2_decimal(n);

    return 0;
}