#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *l, *r;
};

Node* getNode(char ch, int freq, Node* l, Node* r) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->l = l;
    node->r = r;
    return node;
}

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void print(Node* root, string s) {
    if (!root) return;
    if (!root->l && !root->r)
        cout << root->ch << " " << s << "\n";
    print(root->l, s + "0");
    print(root->r, s + "1");
}

int main() {
    int n;
    cin >> n;

    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < n; i++) {
        char c;
        int f;
        cin >> c >> f;
        pq.push(getNode(c, f, NULL, NULL));
    }

    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        pq.push(getNode('$', l->freq + r->freq, l, r));
    }

    print(pq.top(), "");
    return 0;
}
