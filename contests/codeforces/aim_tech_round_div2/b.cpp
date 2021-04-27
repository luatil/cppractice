#include <bits/stdc++.h>
using namespace std;

int arr[55][55];
int sum_line[55];
int sum_col[55];

void printe(int arr[][55], int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
       cout << endl; 
    }
    
}


//retorna total de conjuntos em cada linha
long long total_de_conjuntos_por_linha(int n, int sum) {
    long long zeroth = (powl(2, (n-sum)) - n + sum - 1);
    long long oneth =  (powl(2, sum) - sum - 1);
    return zeroth + oneth;
}

int main(int argc, char const *argv[])
{

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum_line[i] += arr[i][j];
        }
        
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum_col[i] += arr[j][i];
        }
        
    }

    long long bignum = N * M;

    for (int i = 0; i < N; i++)
    {
        bignum += total_de_conjuntos_por_linha(M, sum_line[i]);
        //cout << bignum << endl;
        //cout << endl;
        //cout << sum_line[i] << " ";
    }
    //cout << endl; 
    for (int j = 0; j < M; j++)
    {
       bignum += total_de_conjuntos_por_linha(N, sum_col[j]);
       //cout << bignum << endl;
       //cout << endl;
       //cout << sum_col[j] << " ";
    }
    
    cout << bignum << endl;
    
    return 0;
}
