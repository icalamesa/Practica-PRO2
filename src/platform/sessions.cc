#include "sessions.hh"
#include <algorithm>
#include <iostream>

using namespace std;

Session_repo::Session_repo(){}


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
    return this->session_list.insert(make_pair(new_session.get_id(), new_session)).second;
    //this is using internal Session operator < overload
}

bool Session_repo::insert_session(const string& session_id)
{
    return session_list.insert(make_pair(session_id, Session(session_id))).second;
}

string Session_repo::find_in_sessions(const string& prob) const
{
    string res = "";
    for (const auto& the_session : this->session_list)
    {
	if (the_session.second.find(prob))
	{
	    res = the_session.second.get_id();
	    break;
	}
    }
    return res;
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
