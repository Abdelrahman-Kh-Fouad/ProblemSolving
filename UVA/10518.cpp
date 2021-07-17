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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull n , m ; 
    int tt =0 ; 
    while(cin>> n >>m && (n!=0 || m!=0) )
    {
        MOD = m ;
        vector<vector<int>>a ={{1 ,1 ,1 } , {1 ,0 ,0 } , { 0 ,0 ,1 }};
        vector<int>b ={1 ,1 ,1 };
        Matrix am(a) ;
        Matrix bm = Matrix::vec(b);
        am = power(am , n -1 , m );
        Matrix res = am * bm; 
        // cout<< res.arr[0][0]<<endl;







        // vector<ll>sum(2);
        // sum[0]=sum[1] =(1)%m ;
        // ll lim = 10000;  
        // for(int i = 2 ; i <= (int)10001 ;i++ )
        // {
        //     sum.pb((sum [i-2] + sum[i-1] +1 )%m);
        //     if(sum[i] ==1 &&sum[i-1]  ==1 )
        //     {
        //         lim = i ;
        //         break;
        //     }
        // }
        // lim -- ;
        printf( "Case %d: %lld %d %d\n" ,++tt , n , m ,res.arr[0][0] % m );
    }
    return 0 ; 
}