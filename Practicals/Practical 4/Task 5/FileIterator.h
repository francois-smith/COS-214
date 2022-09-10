/*
 * FileIterator.h
 *
 *  Created on: 2022/09/08.
 *      Author: Francois Smith
 */

#pragma once
#include "NodeIterator.h"

class File;

class FileIterator : public NodeIterator
{
public:
    void first() override;
    void next() override;
    bool hasNext() override;
    Node* current() override;

protected:
    FileIterator(std::vector<File*> files);
    virtual ~FileIterator();
    int currentIndex;
    std::vector<File*> filesList;

    friend class Directory;
};
