#include <exception>
#include <string>
using namespace std;

#include "Node.h"
#include "Folder.h"
#include "Client.h"
#include "Iterator.h"

Node::Node(string aName) {
}

Node::~Node() {
	throw "Not yet implemented";
}

void Node::getName() {
	return this->_name;
}

void Node::setName(string aName) {
	this->_name = aName;
}





