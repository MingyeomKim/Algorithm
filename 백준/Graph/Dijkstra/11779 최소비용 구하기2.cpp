#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define INF 987654321
#define endl '\n'
using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};

vector<Edge> a[1001];
int dist[1001];
bool check[1001];
int v[1001];

int main() {
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); cin.tie(NULL); 
    memset(v, -1, sizeof(v)); 
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        a[x].push_back(Edge(y, z));
    }
    int src, dst; cin >> src >> dst;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int k = 0; k < n - 1; k++) {
        int min = INF;
        int x = -1;
        for (int i = 1; i <= n; i++) {
            if (check[i] == false && dist[i] < min) {
                min = dist[i];
                x = i;
            }
        }

        check[x] = true;
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i].to;
            int cost = a[x][i].cost;
            if (dist[y] > dist[x] + cost) {
                dist[y] = dist[x] + cost;
                v[y] = x;
            }
        }
    }

    stack<int> st; 
    int x = dst; 
    while (x != -1) {
        st.push(x); 
        x = v[x];  // 이전으로 이동
    }

    cout << dist[dst] << endl;
    cout << st.size() << endl;
    while (!st.empty()) {
        cout << st.top() << " "; 
        st.pop(); 
    }
    cout << endl;
    return 0;
}