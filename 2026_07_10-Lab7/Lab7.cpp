#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

// Dijkstra's algorithm using:
// 1. Characters as vertices
// 2. Linked lists for adjacency lists
map<char, int> dijkstra(
    const map<char, list<pair<char, int>>>& adj,
    char src
) {
    // Min-heap storing (distance, vertex)
    priority_queue<
        pair<int, char>,
        vector<pair<int, char>>,
        greater<pair<int, char>>
    > pq;

    // Store the shortest distance for every vertex
    map<char, int> dist;

    // Initially, all distances are infinity
    for (const auto& vertex : adj) {
        dist[vertex.first] = INT_MAX;
    }

    // Distance from the source to itself is 0
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        char currentVertex = pq.top().second;
        pq.pop();

        // Ignore an outdated distance
        if (currentDistance > dist[currentVertex]) {
            continue;
        }

        // Traverse the linked list of neighbours
        for (const pair<char, int>& neighbour : adj.at(currentVertex)) {
            char nextVertex = neighbour.first;
            int weight = neighbour.second;

            // Check whether a shorter path has been found
            if (currentDistance + weight < dist[nextVertex]) {
                dist[nextVertex] = currentDistance + weight;

                pq.push({
                    dist[nextVertex],
                    nextVertex
                });
            }
        }
    }

    return dist;
}

int main() {
    char src = 'A';

    // Each vertex has a linked list of its neighbours
    map<char, list<pair<char, int>>> adj;

    // Graph connections based on the picture
    adj['A'] = {
        {'B', 4},
        {'C', 8}
    };

    adj['B'] = {
        {'A', 4},
        {'C', 3},
        {'E', 6}
    };

    adj['C'] = {
        {'A', 8},
        {'B', 3},
        {'D', 2}
    };

    adj['D'] = {
        {'C', 2},
        {'E', 10}
    };

    adj['E'] = {
        {'B', 6},
        {'D', 10}
    };

    map<char, int> result = dijkstra(adj, src);

    cout << "Shortest distances from vertex " << src << ":" << endl;

    for (const auto& vertex : result) {
        cout << src << " to " << vertex.first << " = ";

        if (vertex.second == INT_MAX) {
            cout << "Infinity";
        } else {
            cout << vertex.second;
        }

        cout << endl;
    }

    return 0;
}