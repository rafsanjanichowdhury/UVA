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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define MAX_N 100010

char str [MAX_N];
int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];

inline bool cmp (const int a, const int b, const int l) { return (y [a] == y [b] && y [a + l] == y [b + l]); }

void Sort () {
    for (int i = 0; i < m; ++i) w [i] = 0;
    for (int i = 0; i < N; ++i) ++w [x [y [i]]];
    for (int i = 0; i < m - 1; ++i) w [i + 1] += w [i];
    for (int i = N - 1; i >= 0; --i) SA [--w [x [y [i]]]] = y [i];
}

void DA () {
    ++N;
    for (int i = 0; i < N; ++i) x [i] = str [i], y[i] = i;
    Sort ();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
        for (p = 0, i = N - j; i < N; i++) y [p++] = i;
        for (int k = 0; k < N; ++k) if (SA [k] >= j) y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i) x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i) SA [i - 1] = SA [i]; --N;
}

void kasaiLCP () {
    for (int i = 0; i < N; ++i) c [SA [i]] = i;
    LCP [0] = 0;
    for (int i = 0, h = 0; i < N; ++i)
        if (c[i] > 0) {
            int j = SA [c [i] - 1];
            while (i + h < N && j + h < N && str [i + h] == str [j + h]) ++h;
                LCP [c [i]] = h;
            if (h > 0) --h;
        }
}

void suffixArray () {
    m = 256;
    N = strlen (str);
    DA ();
    /*kasaiLCP ();

    LL rr=0;
    for(int i = 0; i < N; i++){
        //cout << LCP[i] << ' '<<B[i]<<endl;
        rr+=LL(SA[i])-LCP[i]+1;
    }
    //printf("%d\n",rr);
    return rr;
    */
}

int main(){
    FRO

    gets( str );
    suffixArray();

    for (int i=0;str[i];++i){
        printf("%d\n",SA[i]);
    }
}
