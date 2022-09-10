/*
 * DirectoryIterator.h
 *
 *  Created on: 9/7/22.
 *      Author: Francois Smith
 */

#pragma once
#include "NodeIterator.h"
class Directory;

class DirectoryIterator: public NodeIterator {
public:
    void first() override;
    void next() override;
    bool hasNext() override;
    Node* current() override;

protected:
    DirectoryIterator(std::vector<Directory*> directories);
    virtual ~DirectoryIterator();
    int currentIndex;
    std::vector<Directory*> directoriesList;

    friend class Directory;
};
