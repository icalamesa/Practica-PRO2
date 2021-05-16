#include "sessions.hh"
#include <algorithm>
#include <iostream>

using namespace std;

Session_repo::Session_repo(){}

//these getters absolutely assume the element exists.
Session& Session_repo::get_session(const string& session_id)
{
    return this->session_list.at(session_id);
}

const Session& Session_repo::get_session(const string& session_id) const
{
    return this->session_list.at(session_id);
}

void Session_repo::read_sessions()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
	Session the_session;
	the_session.read_session();
	this->insert_session(the_session);
    }
}

bool Session_repo::exists_session(const string& target) const
{
    return this->session_list.find(target) != this->session_list.end();
}

bool Session_repo::insert_session(const Session& new_session)
{
    //making use of the std::pair return by one of the insert overloads
    //from cppreference:
    //Returns a pair consisting of an iterator to the inserted element (or 
    //to the element that prevented the insertion) 
    //and a bool denoting whether the insertion took place.
    return this->session_list.insert(make_pair(new_session.get_id(), new_session)).second;
}

int Session_repo::size()
{
    return session_list.size();
}

void Session_repo::list_sessions() const
{
    for (const auto& session : this->session_list)
    {
	session.second.info_session();
    }
}

void Session_repo::list_sessions(const string& session_id) const
{
    this->get_session(session_id).info_session();
}

Session_repo::~Session_repo(){}
