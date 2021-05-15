#include "user.hh"
#include <iostream>

using namespace std;

User::User(){}

void User::insertion(const string& problem_id, bool solved)
{
    this->problem_register.emplace(make_pair(problem_id, make_pair(solved, 1)));
}

int User::u_tell_course() const
{
    return this->coursing;
}

bool User::u_is_coursing() const
{
    return coursing != 0;
}

int User::u_amount_attempts() const
{
    return this->total_attempted;
}

int User::u_amount_solved_problems() const
{
    return this->total_successes;
}

int User::u_different_attempts() const
{
    return problem_register.size();
}

//Value modification member function

void User::u_sign_in_course(int course_id)
{
    this->coursing = course_id;
}

//CONTINUAR
void User::u_list_solved() const
{
    for (const auto& problem : this->problem_register)
    {
	if (problem.second.first)
	{
	    cout << problem.first << '(';
	    cout << problem.second.second;
	    cout << ')' << endl;
	}
    }
}

void User::u_list_solvable() const
{
    for (const auto& problem : this->solvable)
    {
	cout << problem << '(';
	auto it = this->problem_register.find(problem); 
	if (it != this->problem_register.end())
	{
	    cout << it->second.second;
	}
	else 
	{
	    cout << '0';
	}
	cout << ')' << endl;
    }
}

void User::info_user() const
{
    cout << '(' << this->u_amount_attempts() << ',';
    cout << this->u_amount_solved_problems() << ',' << this->u_different_attempts();
    cout << ',' << this->u_tell_course() << ')';
    cout << endl;
}

void User::insert_solvable(const string& problem_id)
{
    auto it = this->problem_register.find(problem_id);
    if ((it == this->problem_register.end()) or (it != this->problem_register.end() and it->second.first == false))
    {
	this->solvable.insert(problem_id);
    }
    
}

void User::u_deliver_problem(const string& problem_id, bool success)
{
    this->total_successes += success;
    this->total_attempted++;
    decltype(this->problem_register)::iterator it = this->problem_register.find(problem_id);
    if (it == this->problem_register.end())
    {
	this->insertion(problem_id, success);
    }
    else
    {
	it->second.first or_eq success;
	it->second.second++;
    }
    //remove from solvable list
    if (success)
    {
	this->solvable.erase(problem_id);
    }
}

bool User::u_has_solved_problem(const string& problem_id) const
{
    auto it = this->problem_register.find(problem_id);
    return it != this->problem_register.end() and it->second.first == 1;
}

bool User::u_update_course()
{
    if (this->solvable.empty())
    {
	this->coursing = 0;
	return true;
    }
    return false;
}

User::~User(){}
