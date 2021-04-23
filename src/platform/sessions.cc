#include "sessions.hh"
#include <algorithm>
#include <iostream>

using namespace std;

bool Sessions::comp_by_id(const Session& a, const Session& b)
{
    return a.get_id() < a.get_id();
}

void Sessions::sort_list()
{
    this->session_list.sort();
}

void Sessions::read_sessions()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
	Session the_session;
	the_session.read_session();
	this->insertion(the_session);
    }
    this->sort_list();
}

bool Sessions::exists_session(string target)
{
    return std::binary_search(session_list.begin(), 
	    session_list.end(),
	    Session(target));
}

void Sessions::insertion(const Session& new_session)
{
    session_list.emplace_back(new_session);
}

void Sessions::insert_session(Session new_session)
{
    this->insertion(new_session);
    //this is using internal Session operator < overload
    this->sort_list();
}

void Sessions::insert_session(string session_id)
{
    this->insertion(Session(session_id));
    //this is using internal Session operator < overload
    this->sort_list();
}

string Sessions::find_in_sessions(string prob)
{
    string res = "";
    for (const auto& the_session : this->session_list)
    {
	if (the_session.find(prob))
	{
	    res = the_session.get_id();
	    break;
	}
    }
    return res;
}

int Sessions::size()
{
    return session_list.size();
}
