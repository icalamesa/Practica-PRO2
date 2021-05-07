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

void User::u_sign_in_course(int course_id, Sessions& session_list, Courses& course_list)
{
    this->coursing = course_id;
    this->u_insert_solvable_problems(course_id, session_list, course_list);
    course_list.increase_coursing(course_id);
}

//void User::u_add_problem_to_list(const string& problem_id, bool solved)
//{
    //this->total_attempted++;
    //this->total_successes += solved;
    //decltype(this->solved)::iterator it = this->solved.find(problem_id);
    //if (it != this->solved.end())
    //{
	//it->second.first or_eq solved;
	//it->second.second++;
    //}
    //else
    //{
	//this->insertion(problem_id, solved);
    //}
//}

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
	auto it = this->solved.find(problem); 
	if (it != this->solved.end())
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
    auto it = this->solved.find(problem_id);
    if ((it == this->solved.end()) or (it != this->solved.end() and it->second.first == false))
    {
	this->solvable.insert(problem_id);
    }
    
}

void User::u_insert_solvable_problems(const int& course_id, Sessions& session_list, Courses& course_list)
{
    int course_size = course_list.course_size(course_id);
    for (int i = 0; i < course_size; i++)
    {
	this->insert_solvable(session_list.get_first_problem_id(course_list.get_session_id(course_id, i)));

    }
}

void User::u_deliver_problem(const string& problem_id, bool success, Sessions& session_list, Courses& course_list)
{
    this->total_successes += success;
    this->total_attempted++;
    decltype(this->solved)::iterator it = this->solved.find(problem_id);
    if (it == this->solved.end())
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

    pair<string, string> solvable_candidates;
    int course_size = course_list.course_size(this->u_tell_course());
    string target_session_id;
    for (int i = 0; i < course_size; i++)
    {
	target_session_id = course_list.get_session_id(this->u_tell_course(), i);
	if (session_list.get_session(target_session_id).find(problem_id))
	{
	    break;
	}
    }
    solvable_candidates = session_list.get_next_problems(target_session_id, problem_id);
    if (solvable_candidates.first != string("0"))
    {
	this->insert_solvable(solvable_candidates.first);
    }

    if (solvable_candidates.second != string("0"))
    {
	this->insert_solvable(solvable_candidates.second);
    }

    if (this->solvable.empty())
    {
	course_list.decrease_coursing(this->coursing);
	course_list.increase_completed(this->coursing);
	this->coursing = 0;
    }
}

