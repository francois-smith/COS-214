/*
 * SnapshotStore.h
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#pragma once
#include "Directory.h"
#include "Snapshot.h"

class SnapshotStore
{
public:
    SnapshotStore();
    ~SnapshotStore();
    void storeSnapshot(Snapshot* snapshot);
    Snapshot* getSnapshot();
    void clearSnapshots();

private:
    std::vector<Snapshot*> snapshots;
};
