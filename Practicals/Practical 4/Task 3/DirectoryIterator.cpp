/*
 * DirectoryIterator.cpp
 *
 *  Created on: 9/7/22.
 *      Author: Francois Smith
 */

#include "DirectoryIterator.h"

void DirectoryIterator::first()
{
    this->currentNode = this->firstNode;
}

void DirectoryIterator::next()
{
    this->currentNode = this->currentNode->getNext();
}

bool DirectoryIterator::hasNext()
{
    return false;
}

Node *DirectoryIterator::current()
{
    return this->currentNode;
}
