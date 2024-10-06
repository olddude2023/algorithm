#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;// total number of data
int a[50005],c[50005]; //对应原数组和树状数组

int lowbit(int x){
    return x&(-x);
}
void updata(int i,int val){    //在i位置加上k
    while(i <= n){
        c[i] += val;
        i += lowbit(i);
    }
}

int getsum(int i){        //求c from 1 to i的和
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    for(int tot = 1; tot <= t; tot++){
        cout << "Case " << tot << ":" << endl;
        memset(a, 0, sizeof a);
        memset(c, 0, sizeof c);
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
            updata(i,a[i]);   //输入初值的时候，也相当于更新了值
        }

        string s;
        int x,y;
        while(cin>>s && s[0] != 'E'){
            cin>>x>>y;
            if(s[0] == 'Q'){    //求和操作
                int sum = getsum(y) - getsum(x-1);    //x-y区间和也就等于1-y区间和减去1-(x-1)区间和
                cout << sum << endl;
            }
            else if(s[0] == 'A'){
                updata(x,y);
            }
            else if(s[0] == 'S'){
                updata(x,-y);    //减去操作，即为加上相反数
            }
        }

    }
    return 0;
}
