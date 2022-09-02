#include <exception>
#include <string>
using namespace std;

#ifndef __FolderFactory_h__
#define __FolderFactory_h__

// #include "Node.h"
#include "NodeFactory.h"

class Node;
// class NodeFactory;
class FolderFactory;

class FolderFactory: public NodeFactory
{

	public: Node* createNode(string aName);
};

#endif
