#include "users.hh"
#include <iostream>

using namespace std;

//there is no special requirement of constructor/destructor definition
//since all that is done is handling an internal std::map, which
//already contains a constructor for its stuff
Users::Users(){}
Users::~Users(){}

User& Users::get_user(string user_id)
{
    //no need to say this will crash if prerequisites are not met
    //dereferencing user_list.end() is not a good idea.
    return this->user_find(user_id);
}

User& user_find(const string& user_id)
{
    return user_find(user_id);
}

void Users::insert_user(string user_id)
{
    this->user_list.emplace(std::make_pair(user_id, User()));
}

void Users::remove_user(string user_id)
{
    this->user_list.erase(this->user_list.find(user_id));
}

bool Users::user_exists(string user_id)
{
    return this->user_list.find(user_id) != this->user_list.end();
}

int Users::tell_course(string user_id)
{
    //remember we are assuming its existence
    return this->user_find(user_id).u_tell_course();
}

bool Users::is_coursing(string user_id)
{
    return this->user_find(user_id).u_is_coursing();
}

int Users::amount_attempts(string user_id)
{
    return this->user_find(user_id).u_amount_attempts();
}

int Users::amount_solved_problems(string user_id)
{
    return this->user_find(user_id).u_amount_solved_problems();
}

int Users::different_attempts(string user_id)
{
    return this->user_find(user_id).u_different_attempts();
}

void Users::sign_in_course(string user_id, int course_name)
{
    this->user_find(user_id).u_sign_in_course(course_name);
}

void Users::add_problem_to_list(string user_id, string problem_id, bool solved)
{
    this->user_find(user_id).u_add_problem_to_list(problem_id, solved);
}
//need to do crap with this one
void Users::list_solvable_problems(string user_id)
{
    //this->user_find(user_id).u_
}

void Users::list_users()
{
    //instead of range-based for, we could actually
    //make use of std::for_each, with std::bind to allow use of public members.
    //but it really does not give us any benefit at all.
    for (const auto& user_kv : this->user_list)
    {
	//user_kv is std::pair
	cout << user_kv.first;
	user_kv.second.info_user();
    }
}

void Users::list_solved_problems_by(string user_id)
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



