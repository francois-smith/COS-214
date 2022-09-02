#include <exception>
#include <string>
using namespace std;

#include "File.h"
#include "Node.h"
#include "Iterator.h"

File::File(string aName, string aContent) {
}

File::~File() {
	throw "Not yet implemented";
}

void File::printName() {
	throw "Not yet implemented";
}

void File::getContent() {
	return this->_content;
}

void File::setContent(string aContent) {
	this->_content = aContent;
}

void File::addNode(Node aNewNode) {
	throw "Not yet implemented";
}

bool File::removeNode(Node aNode) {
	throw "Not yet implemented";
}

Iterator* File::createIterator() {
	throw "Not yet implemented";
}

