#include <exception>
#include <string>
using namespace std;

#ifndef __FileFactory_h__
#define __FileFactory_h__

// #include "Node.h"
#include "NodeFactory.h"

class Node;
// class NodeFactory;
class FileFactory;

class FileFactory: public NodeFactory
{

	public: Node* createNode(string aName, string aContent);

	public: Node* createNode(string aName);
};

#endif
