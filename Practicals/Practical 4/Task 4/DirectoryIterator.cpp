/*
 * DirectoryIterator.cpp
 *
 *  Created on: 9/7/22.
 *      Author: Francois Smith
 */

#include "Directory.h"
#include "DirectoryIterator.h"

DirectoryIterator::DirectoryIterator(std::vector<Directory*> directories)
{
    this->currentIndex = 0;
    for(auto directory : directories)
    {
        this->directoriesList.push_back(directory);
    }
}

DirectoryIterator::~DirectoryIterator()
{
    while(!this->directoriesList.empty())
    {
        this->directoriesList.pop_back();
    }
}

void DirectoryIterator::first()
{
    this->currentIndex = 0;
}

void DirectoryIterator::next()
{
    this->currentIndex++;
}

bool DirectoryIterator::hasNext()
{
    return this->currentIndex < this->directoriesList.size();
}

Node* DirectoryIterator::current()
{
    return directoriesList.at(this->currentIndex);
}
