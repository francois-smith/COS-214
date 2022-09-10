/*
 * NodeIterator.h
 *
 *  Created on: 9/7/22.
 *      Author: Francois Smith
 */

#pragma once
#include "Node.h"
#include <vector>

class NodeIterator {
public:
    NodeIterator() = default;
    virtual ~NodeIterator() = default;
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual Node* current() = 0;
};
