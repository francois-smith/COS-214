/*
 * Root.h
 *
 *  Created on: 9/10/22.
 *      Author: Francois Smith
 */

#pragma once
#include "Directory.h"
#include "Antivirus.h"

class SnapshotStore;
class Snapshot;

class Root
{
public:
    Root(Directory* root);
    ~Root();
    Snapshot* createSnapshot();
    void installAntivirus(Antivirus* newAntivirus);
    bool activeAntivirus() const;
    void restoreSnapshot(Snapshot* snapshot);
    Directory* getRoot() const;
    static void clearSnapshots(SnapshotStore* snapshotStore);

private:
    Directory* root;
    Antivirus* antivirus;
};
