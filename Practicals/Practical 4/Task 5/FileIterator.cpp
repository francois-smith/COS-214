/*
 * FileIterator.cpp
 *
 *  Created on: 2022/09/08.
 *      Author: Francois Smith
 */

#include "File.h"
#include "FileIterator.h"

FileIterator::FileIterator(std::vector<File*> files)
{
    this->currentIndex = 0;
    for(auto file : files)
    {
        this->filesList.push_back(file);
    }
}

FileIterator::~FileIterator()
{
    while(!this->filesList.empty())
    {
        this->filesList.pop_back();
    }
}

void FileIterator::first()
{
    this->currentIndex = 0;
}

void FileIterator::next()
{
    this->currentIndex++;
}

bool FileIterator::hasNext()
{
    return this->currentIndex < this->filesList.size();
}

Node* FileIterator::current()
{
    return filesList.at(this->currentIndex);
}
