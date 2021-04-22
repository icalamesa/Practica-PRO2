#include "problem.hh"

using namespace std;

//constructor
Problem::Problem(string problem_id)
{
    this->id = problem_id;
}

string Problem::get_id() const
{
    return this->id;
}

double Problem::get_ratio()
{
    return double(1+this->successful_deliveries) / (1 + this->deliveries);
}

int Problem::get_attempts()
{
    return this->deliveries;
}

int Problem::get_solved()
{
    return this->successful_deliveries;
}
//TO DO
void Problem::info_problem()
{
    string return_str = "";
}

bool Problem::operator==(const Problem& other) const
{
    return this->get_id() == other.get_id();
}

bool Problem::operator<(const Problem& other) const
{
    return this->get_id() < other.get_id();
}
