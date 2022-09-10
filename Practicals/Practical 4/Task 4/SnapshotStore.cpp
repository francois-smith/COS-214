/*
 * SnapshotStore.cpp
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#include "SnapshotStore.h"

SnapshotStore::SnapshotStore()
{
    snapshots = std::vector<Snapshot*>();
}

SnapshotStore::~SnapshotStore()
{
    for(Snapshot* snapshot : snapshots)
    {
        delete snapshot;
    }
}

void SnapshotStore::storeSnapshot(Snapshot *snapshot)
{
    snapshots.push_back(snapshot);
}

Snapshot *SnapshotStore::getSnapshot()
{
    if(snapshots.empty())
    {
        return nullptr;
    }
    else{
        Snapshot* snapshot = snapshots.back();
        snapshots.pop_back();
        return snapshot;
    }
}

void SnapshotStore::clearSnapshots()
{
    for(Snapshot* snapshot : snapshots)
    {
        delete snapshot;
    }
    snapshots.clear();
}
