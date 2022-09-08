#include "Node.h"
#include "Directory.h"
#include "File.h"

int main() {
    Node* root = new Directory("root");
    Node* home = new Directory("home");
    home->addNode(new File("file1", "dwdadawd"));
    root->addNode(home);

    root->printName();

    delete root;
    return 0;
}
