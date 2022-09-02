#include <exception>
#include <string>
using namespace std;

#ifndef __Node_h__
#define __Node_h__

// #include "Folder.h"
// #include "Client.h"
// #include "Iterator.h"

// class Folder;
class Client;
class Iterator;
class Node;

__abstract class Node
{
	private: string _name;
	public: Folder* _unnamed_Folder_;
	public: Client* _unnamed_Client_;

	public: Node(string aName);

	public: ~Node();

	public: void getName();

	public: void setName(string aName);

	public: virtual void printName() = 0;

	public: virtual void addNode(Node aNewNode) = 0;

	public: virtual bool removeNode(Node aNode) = 0;

	public: virtual Iterator* createIterator() = 0;
};

#endif
