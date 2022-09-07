/*
 * Directory.h
 *
 *  Created on: 02 Sep 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Node.h"
#include <string>
#include <vector>

class Directory: public Node
{
public:
    void printName() override;
    void addNode(Node* newNode) override;
    bool removeNode(Node* node) override;
    ~Directory() override;

private:
    std::vector<Node*> nodes;

protected:
    explicit Directory(std::string name);
};

