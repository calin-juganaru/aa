#include "algo.h"

vector<int> shortest_path(const vector<Graph::edge_t>& adj_list, const int& source);

int main()
{
    ifstream fin("./in/test.in");
    ofstream fout("./out/test.out");

    int N, M, source, x, y, z;
    fin >> N >> M >> source;
    auto adj_list = vector<Graph::edge_t>(N + 1);

    while (M--)
    {
        fin >> x >> y >> z;
        adj_list[x].push_back(pair(y, z));
    }
    
    auto dist = shortest_path(adj_list, source);
    print_dist(dist, fout);

    fin.close();
    fout.close();
}
