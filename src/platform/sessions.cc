#include "sessions.hh"
#include <algorithm>
#include <iostream>

using namespace std;

Sessions::Sessions(){}

Session& Sessions::get_session(const string& session_id)
{
    auto ses = Session(session_id);
    return *std::find(this->session_list.begin(), this->session_list.end(), ses);
}

const Session& Sessions::get_session(const string& session_id) const
{
    auto ses = Session(session_id);
    return *std::find(this->session_list.begin(), this->session_list.end(), ses);
}

bool Sessions::comp_by_id(const Session& a, const Session& b)
{
    return a.get_id() < b.get_id();
}

void Sessions::sort_session_list()
{
    this->session_list.sort(std::less<Session>{});
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
    this->sort_session_list();
}

bool Sessions::exists_session(string target) const
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
    this->sort_session_list();
}

void Sessions::insert_session(string session_id)
{
    this->insertion(Session(session_id));
    //this is using internal Session operator < overload
    this->sort_session_list();
}

string Sessions::find_in_sessions(string prob) const
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

int Sessions::session_size(const string& session_id) const
{
    return this->get_session(session_id).size();
}

void Sessions::list_sessions() const
{
    for (const auto& session : this->session_list)
    {
	session.info_session();
    }
}

void Sessions::list_sessions(const string& session_id) const
{
    auto& ses = *(std::find(this->session_list.begin(), 
		this->session_list.end(), 
		Session(session_id)));
    ses.info_session();
}

string Sessions::get_i_problem_id(const string& session_id, int i) const
{
    this->get_session(session_id).get_i_problem(i);
}

Sessions::~Sessions(){}
