/*
 * DirectoryIterator.h
 *
 *  Created on: 9/7/22.
 *      Author: Francois Smith
 */

#pragma once

#include "NodeIterator.h"
#include "Directory.h"

class DirectoryIterator: public NodeIterator {
public:
    explicit DirectoryIterator(Node* first) : NodeIterator(first) {};
    void first() override;
    void next() override;
    bool hasNext() override;
    Node* current() override;

private:

};
