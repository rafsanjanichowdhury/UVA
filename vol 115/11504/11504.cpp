#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 100000
using namespace std;

vector <int> Edges [N + 10];
vector <int> rEdges [N + 10];
bool vis [N + 10];
vector <int> sortedNode;
int comp [N + 10];
int in [N + 10];



void dfs1 (int x)
{
	vis [x] = true;

	for ( int u = 0; u < Edges [x].size (); u++ )
		if ( !vis [Edges [x] [u]] )
            dfs1 (Edges [x] [u]);

	sortedNode.push_back (x);
}

void dfs2 (int x, int c)
{
	vis [x] = false;
	comp [x] = c;

	for ( int u = 0; u < rEdges [x].size (); u++ )
		if ( vis [rEdges [x] [u]] )
            dfs2 (rEdges [x] [u], c);
}

int main ()
{
	int testCase;
	scanf ("%d", &testCase);

	while ( testCase-- )
	{
		int n, m;
		scanf ("%d %d", &n, &m);

        for ( int i = 0; i <= n ; i++ )
        {
            Edges [i].clear ();
            rEdges [i].clear ();
            vis[i]=false;
            in[i]=0;
        }

        sortedNode.clear ();

		for ( int i = 0; i < m; i++ )
		{
			int a, b;
			scanf ("%d %d", &a, &b);
			Edges [a].push_back (b);
			rEdges [b].push_back (a);
		}

		for ( int i = 1; i <= n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = sortedNode.size () - 1; i >= 0; i-- )
			if ( vis [sortedNode [i]] )
                dfs2 (sortedNode [i], ++c);

		for ( int i = 1; i <= n; i++ )
			for ( int j = 0; j < Edges [i].size (); j++ )
				if ( comp [i] != comp [Edges [i] [j]] )
					in [comp [Edges [i] [j]]]++;


		int cnt = 0;

		for ( int i = 1; i <= c; i++ )
			if ( !in [i] )
                cnt++;

		printf ("%d\n", cnt);
	}

	return 0;
}
