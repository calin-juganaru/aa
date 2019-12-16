#include <iostream>
#include <fstream>
#include <random>

#include "graph.h"

using namespace std;

void generate_graph(int N, int M, int source, string file)
{
    ofstream fout(file);
    fout << N << " " << M << " " << source << "\n";

#ifdef DAG
    auto graph = Graph(N);
#endif

    auto edge = vector<vector<bool>>(N + 1,
                       vector<bool>(N + 1));

    auto generator = mt19937(random_device()());
    uniform_int_distribution<> rand_node(1, N);

#ifdef NEG
    uniform_int_distribution<> rand_cost(-N / 2, 2 * N);
#elif defined BIG
    uniform_int_distribution<> rand_cost(1, BIG);
#else
    uniform_int_distribution<> rand_cost(1, N);
#endif

    while (M--)
    {
        auto x = rand_node(generator),
             y = rand_node(generator),
             z = rand_cost(generator);

        while (x == y || edge[x][y])
            y = rand_node(generator);
        
        edge[x][y] = true;
        
#ifdef DAG
        graph.add(x, y, z);
        if (!graph.is_dag())
        {
            graph.remove_last(x);
            ++M; continue;
        }
#endif

        fout << x << " " << y << " " << z << "\n";
    }

    fout.close();
}

int main()
{
    int N, M, S; string F;
    cin >> N >> M >> S >> F;
    generate_graph(N, M, S, F);
}
