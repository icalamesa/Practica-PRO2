#include "user.hh"
#include <iostream>

using namespace std;

User::User(){}
User::~User(){}

void User::insertion(string problem_id, bool solved)
{
    this->solved.emplace(make_pair(problem_id, make_pair(solved, 1)));
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
    return solved.size();
}

//Value modification member function

void User::u_sign_in_course(int course_name)
{
    this->coursing = course_name;
}

void User::u_add_problem_to_list(string problem_id, bool solved)
{
    this->total_attempted++;
    this->total_successes += solved;
    decltype(this->solved)::iterator it = this->solved.find(problem_id);
    if (it != this->solved.end())
    {
	it->second.first or_eq solved;
	it->second.second++;
    }
    else
    {
	this->insertion(problem_id, solved);
    }
}

void User::u_restart_solved_list()
{
    this->total_attempted = 0;
    this->total_successes = 0;
    this->solved.clear();
}
//CONTINUAR
void User::u_list_solved() const
{
    for (const auto& problem : this->solved)
    {
	cout << problem.first << '(';
	//auto it = this->solved.find(problem); 
	//cout << (it != this->solved.end() ? it->second.second : '0');
	cout << '0';
	cout << ')' << endl;
    }
}

void User::u_list_solvable() const
{
    for (const auto& problem : this->solvable)
    {
	cout << problem << '(';
	//auto it = this->solved.find(problem); 
	//cout << (it != this->solved.end() ? it->second.second : '0');
	cout << '0';
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

void User::u_push_problem(const string& problem_id)
{
    auto it = this->solved.find(problem_id);
    if ((it == this->solved.end()) or (it != this->solved.end() and it->second.first == false))
    {
	this->solvable.insert(problem_id);
    }
    
}
