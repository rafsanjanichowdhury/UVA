#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

const double EPS = 1e-2;

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int a,b,c,d,w;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&w);

        int cnt=0,ans = 0;;
        for (int i=a;i<=b;i++ ){
            bool prv=false;
            for (int j=c;j<=d;j++ ){
                cnt+= 1;
                if ( j!= c )
                    cnt+= 10000;
                if ( abs( i-j )<=w  ){
                    if ( prv ){
                        ans+=10000;
                    }
                    ans++;
                    prv=true;
                }
            }
        }
        cout<<cnt<<endl;
        printf("Case #%d: %.7lf\n",kk,double(ans)/cnt);
    }


    return 0;
}
