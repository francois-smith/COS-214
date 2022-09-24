/*
 * Snapshot.h
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#pragma once
#include "Directory.h"
#include <chrono>
#include <ctime>

class Snapshot
{
public:
    ~Snapshot();

private:
    explicit Snapshot(Directory* root);
    Directory* getRoot();
    Directory* root;
    static std::string getTimeStamp();
    std::string timeStamp;

    friend class Root;
};
