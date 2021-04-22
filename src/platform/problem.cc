#include "problem.hh"

using namespace std;

//constructor
Problem::Problem(string problem_id)
{
    this->id = problem_id;
}

string Problem::get_id()
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