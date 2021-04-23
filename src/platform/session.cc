#include "session.hh"

using namespace std;

Session::Session(string session_id)
{
    this->id = id;
}

bool Session::operator< (const Session& other) const
{
    return this->id < other.get_id();
}

string Session::get_id() const
{
    return this->id;
}
