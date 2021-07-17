#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.ff << ", " << p.ss << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    for(int i =0; i< sz(v) ; i++) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}
typedef long long ll;
typedef unsigned long long ull;


ll MOD = 1000000007;
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
                    res.arr[i][j] += ((ll)this->arr[i][k] *x.arr[k][j])%MOD; 
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

Matrix <int> power(Matrix<int> num, ll exp , ll MOD ) {
    Matrix <int>ret = Matrix<int>::I(num.n) ;
    while (exp) {
        if (exp & 1)
            ret = (ret * num)%MOD  ;
        num = (num * num)%MOD ;
        exp >>= 1;
    }
    return ret%MOD ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n ; cin>>n ; 
    vector<vector<int>>a ={{19 , 7 } , {6 ,20}};
    Matrix<int> am (a);
    am = power(am , n , 1000000007);
    cout<<am.arr[0][0]<<endl;
    return 0 ; 
}