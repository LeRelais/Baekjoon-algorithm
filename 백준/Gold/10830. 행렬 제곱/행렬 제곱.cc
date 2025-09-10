#include <iostream>
#include <vector>
using namespace std;

int n;
long long b;
#define MOD 1000

typedef vector<vector<long long>> matrix;

matrix multiply(matrix a, matrix b){
    matrix res(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    
    return res;
}

matrix power (matrix a, long long cnt){
    matrix res(n, vector<long long>(n));
    
    for(int i = 0; i < n; i++){
        res[i][i] = 1;
    }
    
    while(b > 0){
        if(b % 2 != 0){
            res = multiply(res, a);
        }
        
        a = multiply(a, a);

        b /= 2;
    }
    
    return res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> b;
    
    matrix A(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    
    matrix result = power(A, b);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}