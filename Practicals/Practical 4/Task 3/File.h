#include <exception>
#include <string>
using namespace std;

#ifndef __File_h__
#define __File_h__

#include "Node.h"
// #include "Iterator.h"

// class Node;
class Iterator;
class File;

class File: public Node
{
	private: string _content;

	public: File(string aName, string aContent);

	public: ~File();

	public: void printName();

	public: void getContent();

	public: void setContent(string aContent);

	public: void addNode(Node aNewNode);

	public: bool removeNode(Node aNode);

	public: Iterator* createIterator();
};

#endif
