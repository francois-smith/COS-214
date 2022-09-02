#include <exception>
#include <string>
using namespace std;

#ifndef __NodeFactory_h__
#define __NodeFactory_h__

// #include "Node.h"

class Node;
class NodeFactory;

__abstract class NodeFactory
{

	public: virtual Node* createNode(string aName) = 0;
};

#endif
