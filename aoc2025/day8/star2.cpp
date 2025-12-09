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
    ifstream in("day8.txt");
    int x, y, z;
    char c;
    vector<Edge> edges;
    while (in >> x >> c >> y >> c >> z)
    {
        nodes.emplace_back(Point{x, y, z});
    }
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
    ll x1, x2;
    for (int i{0}; i < edges.size(); ++i)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            merge(edges[i].u, edges[i].v);
            x1 = nodes[edges[i].u].x;
            x2 = nodes[edges[i].v].x;
        }
    }
    delete[] par;
    par = nullptr;
    delete[] sz;
    sz = nullptr;
    cout << x1 * x2 << endl;
    return 0;
}
