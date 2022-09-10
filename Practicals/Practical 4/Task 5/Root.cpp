/*
 * Root.cpp
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#include "Snapshot.h"
#include "SnapshotStore.h"
#include "Root.h"

Root::Root(Directory* root)
{
    this->root = root;
}

Root::~Root()
{
    delete root;
}

Snapshot* Root::createSnapshot()
{
    return new Snapshot(this->root);
}

Directory* Root::getRoot() const
{
    return root;
}

void Root::restoreSnapshot(Snapshot* snapshot)
{
    if(snapshot != nullptr)
    {
        std::cout << "\t" << "Restoring previous snapshot from: " << snapshot->timeStamp << std::endl;
        delete root;
        root = dynamic_cast<Directory*>(snapshot->getRoot()->clone());
        delete snapshot;
    }
    else
    {
        std::cout << "\t" << "No snapshots to restore" << std::endl;
    }
}

void Root::clearSnapshots(SnapshotStore* snapshotStore)
{
    snapshotStore->clearSnapshots();
}
