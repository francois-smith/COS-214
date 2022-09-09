/*
 * FileIterator.h
 *
 *  Created on: 2022/09/08.
 *      Author: Francois Smith
 */

#pragma once
#include "NodeIterator.h"

class FileIterator : public NodeIterator {
public:
    FileIterator(Node* node);
    virtual ~FileIterator();
    void first() override;
    void next() override;
    bool hasNext() override;
    void current() override;
};
