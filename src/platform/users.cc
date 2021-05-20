#include "users.hh"
#include <iostream>

using namespace std;

//there is no special requirement of constructor/destructor definition
//since all that is done is handling an internal std::map, which
//already contains a constructor for its stuff
User_repo::User_repo(){}
User_repo::~User_repo(){}

User& User_repo::get_user(const string& user_id)
{
    //no need to say this will crash if prerequisites are not met
    //dereferencing user_list.end() is not a good idea.
    return this->user_list.find(user_id)->second;
}

const User& User_repo::get_user(const string& user_id) const
{
    return this->user_list.find(user_id)->second;
}

void User_repo::insert_user(const string& user_id)
{
    this->user_list.emplace(std::make_pair(user_id, User()));
}

pair<bool, int> User_repo::remove_user(const string& user_id)
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

bool User_repo::user_exists(const string& user_id)
{
    return this->user_list.find(user_id) != this->user_list.end();
}

void User_repo::list_solvable_problems(const string& user_id)
{
    this->get_user(user_id).u_list_solvable();
}

void User_repo::list_users() const
{
    for (auto it = this->user_list.cbegin(); it != this->user_list.cend(); it++)
    {
	this->list_users(it);
    }
}


void User_repo::list_users(const string& user_id) const
{
    auto it = this->user_list.find(user_id);
    this->list_users(it);
}

void User_repo::list_users(const map<string, User>::const_iterator& it) const
{
    cout << it->first;
    it->second.info_user();
}

void User_repo::list_solved_problems_by(const string& user_id)
{
    this->get_user(user_id).u_list_solved();
}

int User_repo::size()
{
    return this->user_list.size();
}

void User_repo::read_users()
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

