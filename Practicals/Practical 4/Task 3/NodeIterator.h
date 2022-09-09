/*
 * NodeIterator.h
 *
 *  Created on: 9/7/22.
 *      Author: Francois Smith
 */

#pragma once

#include "Node.h"

class NodeIterator {
public:
    explicit NodeIterator(Node* first) : firstNode(first), currentNode(first) {};
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual void current() = 0;

protected:
    Node* firstNode;
    Node* currentNode;
};
