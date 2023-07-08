#include <vector>
#include <string>

bool isPossible(int vertex, int i, std::vector<std::vector<int>>& adjLis, std::vector<int>& color) {
    for (int j = 0; j < adjLis[vertex].size(); j++) {
        int it = adjLis[vertex][j];
        if (color[it] == i) {
            return false;
        }
    }
    return true;
}

bool solve(int vertex, std::vector<std::vector<int>>& adjLis, int m, int V, std::vector<int>& color) {
    if (vertex >= V) {
        return true;
    }

    for (int i = 0; i < m; i++) {
        if (isPossible(vertex, i, adjLis, color)) {
            color[vertex] = i;
            if (solve(vertex + 1, adjLis, m, V, color)) {
                return true;
            }
            color[vertex] = -1;
        }
    }
    return false;
}

std::string graphColoring(std::vector<std::vector<int>>& mat, int m) {
    int V = mat.size();
    std::vector<std::vector<int>> adjLis(V);
    std::vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (mat[i][j] == 1) {
                adjLis[i].push_back(j);
                adjLis[j].push_back(i);
            }
        }
    }

    if (solve(0, adjLis, m, V, color)) {
        return "YES";
    }
    return "NO";
}
