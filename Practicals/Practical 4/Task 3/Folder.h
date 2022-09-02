#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Folder_h__
#define __Folder_h__

#include "Node.h"
// #include "NodeIterator.h"
// #include "Iterator.h"

// class Node;
class NodeIterator;
class Iterator;
class Folder;

class Folder: public Node
{
	private: Node* _nodes;
	public: NodeIterator* _unnamed_NodeIterator_;
	public: std::vector<Node*> _unnamed_Node_;

	public: Folder(string aName);

	public: ~Folder();

	public: void printName();

	public: void addNode(Node aNewNode);

	public: bool removeNode(Node aNode);

	public: Iterator* createIterator();
};

#endif
