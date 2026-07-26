vector<vector<int>> mat={
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
for(int i=0;i<3;++i){
    for(int j=0;j<3;++j) {
        cout<<mat[i][j]<< " \n"[j==3-1];
    }
}



vector<int> a = {1, 2, 3, 4, 5, 6};
shuffle(a.begin(),a.end(),mt19937(random_device{}()));



int n=10;
for(int i=0;i<n;++i) {
    cout<<i<<" \n"[i==n-1];
}


bool ok = false;
cout << "NO\0YES" + 3 * ok;

bool x=1;
x&&cout<<"T";




constexpr int64_t mid(int64_t l, int64_t r) {
    return (l & r) + ((l ^ r) >> 1);
}





#define error(...) {string _s=#__VA_ARGS__;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string>_it(_ss);err(_it,__VA_ARGS__);}
void err(istream_iterator<string>){}
template<class T,class...Args>
void err(istream_iterator<string>it,T a,Args...args){
    cerr<<*it<<" = "<<a<<'\n';
    err(++it,args...);
}
