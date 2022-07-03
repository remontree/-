#include <bits/stdc++.h>
using namespace std;
 
int n, p, ans;
int flow[401][401];
int capacity[401][401];
vector<vector<int>> adj;
const int src = 1, dst = 2;
 
void edmonds_karp() {
 
	while (1)
	{
		queue<int> q;
		q.push(src);
		vector<int> parent(n + 1, -1);
		int minflow = 987654321;
 
		while (!q.empty()) {
			
			int cur = q.front(); q.pop();
 
			for (int next : adj[cur]) 
				if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
					q.push(next);
					parent[next] = cur;
					if (next == dst)	break;
				}
		}
 
		if (parent[dst] == -1) break;
 
		for (int i = dst; i != src; i = parent[i]) 
			minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
		
		for (int i = dst; i != src; i = parent[i])
		{
			flow[parent[i]][i] += minflow;
			flow[i][parent[i]] -= minflow;
		}
		ans += minflow;
	}
 
	return;
}
 
int main()
{
	scanf("%d %d", &n, &p);
 
	adj.resize(n + 1);
 
	for (int i = 0; i < p; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from].push_back(to);
		adj[to].push_back(from);
		capacity[from][to] = 1;
	}
 
	edmonds_karp();
 
	printf("%d", ans);
 
	return 0;
}