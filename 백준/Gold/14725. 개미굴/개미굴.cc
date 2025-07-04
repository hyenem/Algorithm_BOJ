#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
class Node{
public :
    Node(){}
    Node(int depth, string name, map<string, Node> child): depth(depth), name(name), child(child){}
    int depth;
    string name;
    map<string, Node> child;
};
void printTree(Node& node){
    if(node.depth!=-1){
        for (size_t i = 0; i < node.depth; i++)
        {
            cout << "--";
        }
        cout << node.name<<endl;
    }

    for(auto itr = node.child.begin(); itr != node.child.end(); itr++) {
        printTree(itr->second);
    }
}
int main() {
    int N;
    cin >> N;

    Node root(-1, "root", {});
    for (size_t i = 0; i < N; i++)
    {
        int K;
        cin >> K;

        Node *cur = &root;
        for (size_t j = 0; j < K; j++)
        {
            string next;
            cin >> next;
            if(cur->child.find(next)!=cur->child.end()){
                cur = &(cur->child[next]);
            } else {
                cur->child.insert({next, Node(cur->depth+1, next, {})});
                cur = &(cur->child[next]);
            }
        }

    }
    printTree(root);
    return 0;
}