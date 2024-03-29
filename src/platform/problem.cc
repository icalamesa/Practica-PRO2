#include "problem.hh"
#include <iostream>

using namespace std;

Problem::Problem(){}

Problem::Problem(const string& problem_id)
{
    this->id = problem_id;
}

string Problem::get_id() const
{
    return this->id;
}

double Problem::get_ratio() const
{
    return this->ratio;
}

int Problem::get_attempts() const
{
    return this->submissions;
}

int Problem::get_solved() const
{
    return this->successful_submissions;
}
//TO DO
void Problem::info_problem() const
{
    cout << this->get_id();
    cout << '(' << this->get_attempts() << ',';
    cout << this->get_solved() << ',' << this->get_ratio();
    cout << ')' <<endl;
}

bool Problem::operator==(const Problem& other) const
{
    return this->get_id() == other.get_id();
}

bool Problem::operator<(const Problem& other) const
{
    return this->get_id() < other.get_id();
}

void Problem::recalculate_ratio()
{
    this->ratio = double(1 + submissions)/(1 +successful_submissions );
}

void Problem::problem_submission(bool success)
{
    this->submissions++;
    this->successful_submissions += success;
    this->recalculate_ratio();
}

Problem::~Problem(){}
