#include "sessions.hh"
#include <algorithm>
#include <iostream>

using namespace std;

Sessions::Sessions(){}


Session& Sessions::get_session(const string& session_id)
{
    return this->session_list.at(session_id);
}

const Session& Sessions::get_session(const string& session_id) const
{
    return this->session_list.at(session_id);
}

void Sessions::read_sessions()
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

bool Sessions::exists_session(const string& target) const
{
    return this->session_list.find(target) != this->session_list.end();
}

bool Sessions::insert_session(const Session& new_session)
{
    return this->session_list.insert(make_pair(new_session.get_id(), new_session)).second;
    //this is using internal Session operator < overload
}

bool Sessions::insert_session(const string& session_id)
{
    return session_list.insert(make_pair(session_id, Session(session_id))).second;
}

string Sessions::find_in_sessions(const string& prob) const
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

int Sessions::size()
{
    return session_list.size();
}

int Sessions::session_size(const string& session_id) const
{
    return this->get_session(session_id).size();
}

void Sessions::list_sessions() const
{
    for (const auto& session : this->session_list)
    {
	session.second.info_session();
    }
}

void Sessions::list_sessions(const string& session_id) const
{
    this->get_session(session_id).info_session();
}


string Sessions::get_i_problem_id(const string& session_id, int i) const
{
    return this->get_session(session_id).get_i_problem(i);
}

pair<string, string> Sessions::get_next_problems(const string& session_id, const string& problem_id) const
{
    return this->get_session(session_id).get_next_problems(problem_id);
}

Sessions::~Sessions(){}
