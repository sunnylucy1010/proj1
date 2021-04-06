// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define V 4

// implementation of travelling Salesman Problem
vector<int> TSP_bruteForce(vector<vector<int>> graph, int s)
{
    // store all vertex apart from source vertex
    vector<vector<int>> route(6);
    vector<int> vertex;
    vector<int> res;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    int j = 0;
    do
    {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        route[j].push_back(s);
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // update minimum
        for (int i = 0; i < V - 1; i++)
            route[j].push_back(vertex[i]);

        route[j].push_back(current_pathweight);

        min_path = min(min_path, current_pathweight);
        j++;
    } while (next_permutation(vertex.begin(), vertex.end()));

    for (int i = 0; i < 6; i++)
    {
        if (min_path == route[i][4])
            for (int k = 0; k < V; k++)
            {
                cout << route[i][k] << " ";
                res = route[i];
            }
    }
    cout << res[V];
    return res;
}

void TSP_file(vector<vector<int>> &graph)
{
    int n;
    string myArray;
    ifstream file("TSP_file.txt");
    int temp = 0;
    file >> myArray;
    stringstream geek(myArray);
    geek >> n;
    int length = n * n;
    string Arr[length];
    cout << "Initial graph: " << endl;
    for (int i = 0; i < n; i++)
    {
        graph.push_back({});
        for (int j = 0; j < n; j++)
        {
            file >> Arr[i * n + j];
            stringstream geek(Arr[i * n + j]);
            geek >> temp;
            graph[i].push_back(temp);
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> res = TSP_bruteForce(graph, 0);

    ofstream writeFile("TSP_file.txt");
    writeFile << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            writeFile << graph[i][j] << " ";
        }
        writeFile << endl;
    }
    for (int i = 0; i <= n; i++)
        writeFile << res[i] << " ";
    writeFile.close();
}

void randomGraph(vector<vector<int>> &graph)
{
    int bound, s, n;
    cout << "Number of cities: ";
    cin >> n;
    cout << "Input bound: ";
    cin >> bound;
    cout << "Starting point: ";
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        graph.push_back({});
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i].push_back(0);
            else
                graph[i].push_back(rand() % bound + 1);
        }
    }
    TSP_bruteForce(graph, s);
}

void keyboardGraph()
{
    int n, temp, s;
    vector<vector<int>> graph;
    cout << "Number of cities: ";
    cin >> n;
    cout << "Starting point: ";
    cin >> s;
    cout << "Graph: " << endl;
    for (int i = 0; i < n; i++)
    {
        graph.push_back({});
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            graph[i].push_back(temp);
        }
    }
    TSP_bruteForce(graph, s);
}
// Driver Code
int main()
{
    vector<vector<int>> graph;
    //keyboardGraph();
    // randomGraph(graph);
    TSP_file(graph);
    return 0;
}
