#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b;
    char arr[8][8];
    cin>>t;
    for(int u=0;u<t;u++)
    {
        a=0;
        b=0;
        //cout<<" "<<endl;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cin>>arr[i][j];
            }
        }
 
        for(int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                if(arr[i][j] == 'R' && arr[i][j+1] == 'R' && arr[i][j+2] == 'R'&& arr[i][j+3] == 'R'&& arr[i][j+4] == 'R'&& arr[i][j+5] == 'R'&& arr[i][j+6] == 'R' && arr[i][j+7] == 'R')
                a++;
            }
        }
 
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if(arr[i][j] == 'B' && arr[i+1][j] == 'B' && arr[i+2][j] == 'B'&& arr[i+3][j] == 'B'&& arr[i+4][j] == 'B'&& arr[i+5][j] == 'B'&& arr[i+6][j] == 'B' && arr[i+7][j] == 'B')
                b++;
            }
        }
 
        if(a>0)
        cout<<"R"<<endl;
        else if(b>0)
        cout<<"B"<<endl;
        
 
 
    }
 return 0;
}
