#include "users.hh"
#include <iostream>

using namespace std;

//there is no special requirement of constructor/destructor definition
//since all that is done is handling an internal std::map, which
//already contains a constructor for its stuff
Users::Users(){}
Users::~Users(){}

User& Users::get_user(const string& user_id)
{
    //no need to say this will crash if prerequisites are not met
    //dereferencing user_list.end() is not a good idea.
    return this->user_list.find(user_id)->second;
}

const User& Users::get_user(const string& user_id) const
{
    return this->user_list.find(user_id)->second;
}

User& Users::user_find(const string& user_id)
{
    return this->user_list.find(user_id)->second;
}

void Users::insert_user(const string& user_id)
{
    this->user_list.emplace(std::make_pair(user_id, User()));
}

pair<bool, int> Users::remove_user(const string& user_id)
{
    auto it = this->user_list.find(user_id);
    int course = -1;
    if (it != this->user_list.end())
    {
	if (it->second.u_is_coursing())
	{
	    course = it->second.u_tell_course();
	}
	this->user_list.erase(it);
	return make_pair(true, course);
    }
    else return make_pair(false, course);
}

bool Users::user_exists(const string& user_id)
{
    return this->user_list.find(user_id) != this->user_list.end();
}

void Users::list_solvable_problems(const string& user_id)
{
    this->user_find(user_id).u_list_solvable();
}

void Users::list_users() const
{
    for (auto it = this->user_list.begin(); it != this->user_list.end(); it++)
    {
	this->list_users(it);
    }
}


void Users::list_users(const string& user_id) const
{
    auto it = this->user_list.find(user_id);
    this->list_users(it);
}

void Users::list_users(decltype(Users::user_list)::const_iterator& it) const
{
    cout << it->first;
    it->second.info_user();
}

void Users::list_solved_problems_by(const string& user_id)
{
    this->user_find(user_id).u_list_solved();
}

int Users::size()
{
    return this->user_list.size();
}

void Users::read_users()
{
    int n;
    cin >> n;
    string user_id;
    for (int i = 0; i < n; i++)
    {
	cin >> user_id;
	this->insert_user(user_id);
    }
}

