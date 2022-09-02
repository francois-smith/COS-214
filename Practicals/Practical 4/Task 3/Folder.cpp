#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "Folder.h"
#include "Node.h"
#include "NodeIterator.h"
#include "Iterator.h"

Folder::Folder(string aName) {
}

Folder::~Folder() {
	throw "Not yet implemented";
}

void Folder::printName() {
	throw "Not yet implemented";
}

void Folder::addNode(Node aNewNode) {
	throw "Not yet implemented";
}

bool Folder::removeNode(Node aNode) {
	throw "Not yet implemented";
}

Iterator* Folder::createIterator() {
	throw "Not yet implemented";
}

