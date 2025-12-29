#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Point
{
    ll x, y, z;
};

vector<Point> nodes;
int *par;
ll *sz;

struct Edge
{
    int u, v;
    ll w;
    Edge(int u, int v)
        : u(u), v(v),
          w((nodes[u].x - nodes[v].x) * (nodes[u].x - nodes[v].x) +
            (nodes[u].y - nodes[v].y) * (nodes[u].y - nodes[v].y) +
            (nodes[u].z - nodes[v].z) * (nodes[u].z - nodes[v].z))
    {
    }

    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

int find(int x)
{
    return par[x] == x ? x : (par[x] = find(par[x]));
}

void merge(int x, int y)
{
    int px{find(x)}, py{find(y)};
    if (px == py)
    {
        return;
    }
    if (sz[px] >= sz[py])
    {
        swap(px, py);
    }
    par[px] = py;
    sz[py] += sz[px];
    sz[px] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day8.txt");
    int x, y, z;
    char c;
    vector<Edge> edges;
    while (in >> x >> c >> y >> c >> z)
    {
        nodes.emplace_back(Point{x, y, z});
    }
    in.close();
    for (int i{0}; i < nodes.size() - 1; ++i)
    {
        for (int j{i + 1}; j < nodes.size(); ++j)
        {
            edges.emplace_back(Edge{i, j});
        }
    }
    sort(edges.begin(), edges.end());
    par = new int[nodes.size()];
    sz = new ll[nodes.size()];
    for (size_t i{0}; i < nodes.size(); ++i)
    {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i{0}; i < 1000; ++i)
    {
        merge(edges[i].u, edges[i].v);
    }
    delete[] par;
    par = nullptr;
    sort(sz, sz + nodes.size(), greater<ll>());
    cout << sz[0] * sz[1] * sz[2] << endl;
    delete[] sz;
    sz = nullptr;
    return 0;
}
