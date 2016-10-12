
#include <string.h>
#include <stdio.h>
#include <algorithm>

// the maximum number of vertices
#define NN 104

using namespace std;

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int cap[NN][NN], deg[NN], adj[NN][NN];

// BFS stuff
int q[NN], prev[NN];

int dinic( int n, int s, int t )
{
    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        int qf = 0, qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prev[v = adj[u][i]] == -1 && cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // try finding more paths
        for( int z = 0; z < n; z++ ) if( cap[z][t] && prev[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
                bot = (bot>cap[u][v])?cap[u][v]:bot;
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}

//----------------- EXAMPLE USAGE -----------------
int main()
{
    freopen("in.txt","r",stdin);
    // read a graph into cap[][]

    int n, s, t, m ,cases=0;

    while( scanf( "%d %d %d %d", &n, &s, &t, &m )==4 && n){
        s--;
        t--;
        memset( cap, 0, sizeof( cap ) );
        while( m-- )
        {
            int u, v, c;
            scanf( "%d %d %d", &u, &v, &c );
            u--;
            v--;
            cap[u][v] +=c;
            cap[v][u] +=c;
        }

        // init the adjacency list adj[][] from cap[][]
        memset( deg, 0, sizeof( deg ) );
        for( int u = 0; u < n; u++ )
            for( int v = 0; v < n; v++ ) if( cap[u][v] || cap[v][u] )
                adj[u][deg[u]++] = v;

        printf("Network %d\n",++cases);
        printf("The bandwidth is %d.\n\n",dinic(n,s,t) );
    }



    return 0;
}
