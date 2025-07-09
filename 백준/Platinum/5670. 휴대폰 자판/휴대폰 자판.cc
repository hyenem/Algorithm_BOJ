#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <iomanip>

using namespace std;
class Node{
public :
    Node(){}
    Node(char name, unordered_map<char, Node*> child) : name(name), child(child){}
    char name;
    unordered_map<char, Node*> child;
    char isend = 0;
};

int ans;
Node root;
void calc(Node* n, int depth){
    if(n->isend) ans += depth;
    
    if(n==&root || n->isend || n->child.size()>1) depth += 1;
    
    for(auto& pair : n->child){
        calc(pair.second, depth);
    }
}
int main() {
    int N;
    while(cin>>N){

        root.child.clear();
        for (int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            Node* cur = &root;
            for (size_t j = 0; j < s.size(); j++)
            {
                if(cur->child.find(s.at(j))==cur->child.end()){
                    cur->child.insert({s.at(j), new Node(s.at(j), {})});
                }
                cur = cur->child[s.at(j)];
            }
            cur->isend = 1;
        }

        ans = 0;
        calc(&root, 0);
        cout << fixed << setprecision(2) << (double)ans/(double)N <<endl;
    }

    return 0;
}