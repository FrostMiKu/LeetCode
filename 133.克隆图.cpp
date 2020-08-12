/*
https://leetcode-cn.com/problems/clone-graph/

LeetCode怎么回事，十道题里九道都是电风扇，LeetCode是多喜欢DFS啊...
这题很简单，弄个map记录一下哪个节点访问过了就行了
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
*/

class Solution {
    unordered_map<Node*,Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;

        if(visited.find(node) != visited.end()) return visited[node];

        Node* newNode = new Node(node->val);

        visited[node] = newNode;

        for(int i=0; i<node->neighbors.size(); i++){
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        
        return newNode;
    }
};