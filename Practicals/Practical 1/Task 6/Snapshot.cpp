#include "snapshot.h"

Snapshot::Snapshot(const std::string &state) : state_(state)
{
    this->state_ = state;
    time_t now = time(nullptr);
    this->date_ = ctime(&now);
}

std::string Snapshot::GetUsername() const
{
    return this->date_ + "(" + this->state_.substr(0, 9) + "...)";
}

std::string Snapshot::date() const
{
    return this->date_;
}

std::string Snapshot::state() const
{
    return this->state_;
}
