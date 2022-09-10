/*
 * Snapshot.cpp
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#include "Snapshot.h"

Snapshot::Snapshot(Directory *root)
{
    std::string time = getTimeStamp();
    std::cout << "\t" << "Storing snapshot at timestamp: " << time << std::endl;
    this->timeStamp = time;
    Node* newRoot = root->clone();
    this->root = dynamic_cast<Directory*>(newRoot);
}

Snapshot::~Snapshot()
{
    delete root;
}

Directory* Snapshot::getRoot()
{
    return root;
}

std::string Snapshot::getTimeStamp()
{
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    return std::ctime(&end_time);
}