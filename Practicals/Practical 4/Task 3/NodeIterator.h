#include <exception>
#include <string>
using namespace std;

#ifndef __NodeIterator_h__
#define __NodeIterator_h__

// #include "Node.h"
// #include "Folder.h"
#include "Iterator.h"

class Node;
class Folder;
// class Iterator;
class NodeIterator;

class NodeIterator: public Iterator
{
	private: Node* _firstItem;
	private: Node* _currentItem;
	public: Folder* _unnamed_Folder_;

	public: NodeIterator(Node* aFirstItem);

	public: ~NodeIterator();

	public: void first();

	public: void next();

	public: bool hasNext();

	public: string current();
};

#endif
