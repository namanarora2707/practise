#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

class graph {
public:
    map<string, list<string>> adj;

    void addEdge(string u, string v, bool bidir = true) {
        adj[u].push_back(v);
        if (bidir) {
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto p : adj) {
            cout << p.first << " : ";
            for (auto ch : p.second) {
                cout << ch << " ";
            }
            cout << endl;
        }
    }

    void bfs(string src) {
        unordered_map<string, bool> visited;
        queue<string> q;

        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            string f = q.front();
            q.pop();

            cout << f << " ";
            for (auto ch : adj[f]) {
                if (!visited[ch]) {
                    q.push(ch);
                    visited[ch] = true;
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(string src, unordered_map<string, bool> &visited) {
        cout << src << " ";
        visited[src] = true;

        for (auto ch : adj[src]) {
            if (!visited[ch]) {
                dfsHelper(ch, visited);
            }
        }
    }
    void dfs(string src) {
        unordered_map<string, bool> visited;
        dfsHelper(src, visited);
        cout << endl;
    }

    void componentsCount() {
        unordered_map<string, bool> visited;
        int component = 0;

        for (auto p : adj) {
            if (!visited[p.first]) {
                component++;
                cout << "Component " << component << " → ";
                dfsHelper(p.first, visited);  
                cout << endl;
            }
        }

        cout << "\nTotal Components : " << component << endl;
    }

    void SSSP(string src, string des) {
        unordered_map<string, bool> visited;
        unordered_map<string, int> dist;
        unordered_map<string, string> parent;

        queue<string> q;

        visited[src] = true;
        dist[src] = 0;
        parent[src] = src;

        q.push(src);

        while (!q.empty()) {
            string f = q.front();
            q.pop();

            for (auto ch : adj[f]) {
                if (!visited[ch]) {
                    visited[ch] = true;
                    parent[ch] = f;
                    dist[ch] = dist[f] + 1;
                    q.push(ch);
                }
            }
        }

        cout << "\nDistance from " << src << " to " << des << " = " << dist[des] << endl;

        // Print Path
        vector<string> path;
        while (des != parent[des]) {
            path.push_back(des);
            des = parent[des];
        }
        path.push_back(des);

        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (auto x : path) cout << x << " -> ";
        cout << "END\n";
    }
};

int main() {
    graph g;
    g.addEdge("D","B");
    g.addEdge("D","C");
   g.addEdge("A","B");
   g.addEdge("A","C");
   g.addEdge("E","C");
   g.addEdge("E","D");
   g.addEdge("E","F");
   g.addEdge("G","H");
   g.addEdge("I","K");
   g.bfs("A");

    return 0;
}
