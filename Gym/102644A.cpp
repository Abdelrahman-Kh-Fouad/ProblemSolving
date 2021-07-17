#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll ;
typedef unsigned long long ull ;


ll MOD = 1e9 + 7 ;
template <typename T> 
class Matrix{
public :
    int n ,m ;
    vector<vector<T>>arr;
public :
    Matrix(int n ,int m ): n(n), m(m){
        arr.assign(n ,vector<T>(m, 0 ));
    }
    Matrix(vector<vector<T>> &arr):n(arr.size()), m(arr.front().size()){
        this->arr = arr ; 
    }
    static Matrix I (int n ){
        Matrix res (n , n);
        for(int i =0 ;i < n ;i++)
            res.arr[i][i] =1 ; 
        return res ; 
    }
    static Matrix vec (vector<T> &arr ){
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
                    res.arr[i][j] += (this->arr[i][k] *x.arr[k][j]); 
        return res ;
    }
    Matrix operator % (T mod){
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

Matrix <double> power(Matrix<double> num, ll exp ) {
    Matrix <double>ret = Matrix<double>::I(num.n) ;
    while (exp) {
        if (exp & 1)
            ret = (ret * num)  ;
        num = (num * num) ;
        exp >>= 1;
    }
    return ret ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n ; double p ; 
    cin>>n>> p ;
    vector<vector<double>>a = {{1- p ,  p}, {p , 1 -p} };
    Matrix<double> am (a);
    am = power(am ,n);
    printf("%0.9f\n" , am.arr[0][0]);

    return 0 ; 
}