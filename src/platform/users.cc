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
    return this->user_find(user_id);
}

User& Users::user_find(const string& user_id)
{
    return this->user_list.find(user_id)->second;
}

void Users::insert_user(const string& user_id)
{
    this->user_list.emplace(std::make_pair(user_id, User()));
}

void Users::remove_user(const string& user_id)
{
    this->user_list.erase(this->user_list.find(user_id));
}

bool Users::user_exists(const string& user_id)
{
    return this->user_list.find(user_id) != this->user_list.end();
}

int Users::tell_course(const string& user_id)
{
    //remember we are assuming its existence
    return this->user_find(user_id).u_tell_course();
}

bool Users::is_coursing(const string& user_id)
{
    return this->user_find(user_id).u_is_coursing();
}

int Users::amount_attempts(const string& user_id)
{
    return this->user_find(user_id).u_amount_attempts();
}

int Users::amount_solved_problems(const string& user_id)
{
    return this->user_find(user_id).u_amount_solved_problems();
}

int Users::different_attempts(const string& user_id)
{
    return this->user_find(user_id).u_different_attempts();
}

void Users::sign_in_course(const string& user_id, int course_name)
{
    auto& user = this->user_find(user_id);
    user.u_sign_in_course(course_name);
}

void Users::add_problem_to_list(const string& user_id, const string& problem_id, bool solved)
{
    this->user_find(user_id).u_add_problem_to_list(problem_id, solved);
}
//need to do crap with this one
void Users::list_solvable_problems(const string& user_id)
{
    this->user_find(user_id).u_list_solvable();
}

void Users::list_users() const
{
    //instead of range-based for, we could actually
    //make use of std::for_each, with std::bind to allow use of public members.
    //but it really does not give us any benefit at all.
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

void Users::push_problem(const string& user_id, const string& problem_id)
{
    this->get_user(user_id).u_push_problem(problem_id);
}


