#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        vector<Node*> neighbours;
        Node* cur = new Node(node->val);
        mp[node] = cur;

        for (auto it : node->neighbors) {
            if (mp.find(it) != mp.end()) {
                neighbours.push_back(mp[it]);
            } else {
                neighbours.push_back(dfs(it, mp));
            }
        }
        cur->neighbors = neighbours;
        return cur;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};

// Helper function to build graph from an adjacency list
Node* buildGraph(const vector<vector<int>>& adjList) {
    if (adjList.empty()) return nullptr;

    int n = adjList.size();
    vector<Node*> nodes(n + 1, nullptr);

    for (int i = 1; i <= n; ++i) {
        nodes[i] = new Node(i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int neighborVal : adjList[i - 1]) {
            nodes[i]->neighbors.push_back(nodes[neighborVal]);
        }
    }

    return nodes[1];
}

// Helper function to print graph nodes and memory addresses (BFS)
void printGraph(Node* node) {
    if (!node) {
        cout << "Graph is empty." << endl;
        return;
    }

    unordered_map<Node*, bool> visited;
    queue<Node*> q;

    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Node " << curr->val << " [Addr: " << curr << "] -> Neighbors: [";
        for (size_t i = 0; i < curr->neighbors.size(); ++i) {
            cout << curr->neighbors[i]->val << " (Addr: " << curr->neighbors[i] << ")";
            if (i + 1 < curr->neighbors.size()) cout << ", ";
        }
        cout << "]\n";

        for (auto neighbor : curr->neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Helper function to free allocated dynamic memory
void deleteGraph(Node* node) {
    if (!node) return;

    unordered_set<Node*> visited;
    queue<Node*> q;

    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        for (auto neighbor : curr->neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
        delete curr;
    }
}

int main() {
    int numNodes;
    cout << "Enter total number of nodes in graph (0 for empty graph): ";
    if (!(cin >> numNodes) || numNodes <= 0) {
        cout << "\n=== Original Graph Structure ===" << endl;
        printGraph(nullptr);
        cout << "\n=== Cloned Graph Structure ===" << endl;
        printGraph(nullptr);
        return 0;
    }

    vector<vector<int>> adjList(numNodes);

    cout << "\n--- Enter Neighbors for Each Node (1 to " << numNodes << ") ---" << endl;
    for (int i = 1; i <= numNodes; ++i) {
        int neighborCount;
        cout << "Enter number of neighbors for Node " << i << ": ";
        cin >> neighborCount;

        if (neighborCount > 0) {
            cout << "Enter " << neighborCount << " neighbor ID(s) (1-indexed, separated by space): ";
            for (int j = 0; j < neighborCount; ++j) {
                int neighborVal;
                cin >> neighborVal;
                adjList[i - 1].push_back(neighborVal);
            }
        }
    }

    // 1. Construct original graph
    Node* original = buildGraph(adjList);

    cout << "\n=== Original Graph Structure ===" << endl;
    printGraph(original);

    // 2. Clone graph using Solution
    Solution sol;
    Node* cloned = sol.cloneGraph(original);

    cout << "\n=== Cloned Graph Structure ===" << endl;
    printGraph(cloned);

    // 3. Clean up memory
    deleteGraph(original);
    deleteGraph(cloned);

    return 0;
}