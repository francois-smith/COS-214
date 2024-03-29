#pragma once

#include <ctime>
#include "AuditableSnapshot.h"

class Snapshot: public AuditableSnapshot
{
private:
    std::string state_;
    std::string date_;
    explicit Snapshot(const std::string& state);
    std::string GetUsername() const override;
    std::string date() const override;
    std::string state() const override;
    friend class User;
};