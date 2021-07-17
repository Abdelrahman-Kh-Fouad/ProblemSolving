#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
ll MOD = 1e9 + 7 ;
class Matrix{
public :
    int n ,m ;
    vector<vector<int>>arr;
public :
    Matrix(int n ,int m ): n(n), m(m){
        arr.assign(n ,vector<int>(m, 0 ));
    }
    Matrix(vector<vector<int>> &arr):n(arr.size()), m(arr.front().size()){
        this->arr = arr ; 
    }
    static Matrix I (int n ){
        Matrix res (n , n);
        for(int i =0 ;i < n ;i++)
            res.arr[i][i] =1 ; 
        return res ; 
    }
    static Matrix vec (vector<int> &arr ){
        Matrix res(arr.size(),1) ;

        for(int i =0 ;i < res.n ;i+=1)
            res.arr[i][0] =arr[i];
        return res ;
    }
    Matrix operator * (const int x ){
        Matrix res =*this ;
        for(int i =0 ;i < n ; i++)
            for(int j =0 ;j < m ;j++)
                res.arr[i][j] *=x ;
        return res ;

    }
    Matrix operator * (const Matrix &x ){
        Matrix res(this->n ,x.m);
        for(int i =0 ;i < this->n ;i++ )
            for(int j =0 ;j < this->m ;j++)
                for(int k = 0 ;k< this-> m ; k++)
                    res.arr[i][j] += ((ll)this->arr[i][k] *(ll)x.arr[k][j])%MOD; 
        return res ;
    }
    Matrix operator % (ll mod){
        Matrix res (n , m);
        for(int i = 0 ; i < this->n ;i++ )
            for(int j = 0 ; j < this->m ;j++)
                res.arr[i][j] =  this->arr[i][j] %= mod; 
        return res ;
    }
    void print(){
        for(int i =0 ;i < n ;i++)
        {
            for(int j =0 ;j < m ;j++)
                cout<< arr[i][j]<<" ";
            cout<<endl;
        }
    } 

};

Matrix power(Matrix &num, ll exp , ll m) {
    Matrix ret = Matrix::I(num.n) ;
    while (exp) {
        if (exp & 1)
            ret = (ret * num) % m ;
        num = (num * num) % m ;
        exp >>= 1;
    }
    return ret % m;
}

void solve()
{
    ll n ;cin>>n ; 
    vector<vector<int>>aa ={{0 ,1 } , {1 ,1 }};
    vector<int>bb ={0, 1};
    Matrix a (aa);
    Matrix b = Matrix::vec(bb);
    a = power(a , n , 1e9 +7 );
    Matrix res =a * b ; 
    cout << res.arr[0][0]% (ll)(1e9 + 7)<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0 ; 
}