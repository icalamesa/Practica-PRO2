#include "problems.hh"
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

Problem_repo::Problem_repo(){}

Problem& Problem_repo::get_problem(const string& problem_id)
{ 
   return this->problem_list.find(problem_id)->second;
}

const Problem& Problem_repo::get_problem(const string& problem_id) const
{ 
   return this->problem_list.find(problem_id)->second;
}

bool Problem_repo::problem_exists(const string& problem_id)
{
    return this->problem_list.find(problem_id) != this->problem_list.end();
}

int Problem_repo::size()
{
    return problem_list.size();
}

bool Problem_repo::insert_problem(const string& problem_id)
{
    return this->problem_list.insert(make_pair(problem_id, Problem(problem_id))).second;
}

void Problem_repo::read_problems()
{
    int n;
    cin >> n;
    string problem_id;
    for (int i = 0; i < n; i++)
    {
        cin >> problem_id;
        this->insert_problem(problem_id);
    }
}

void Problem_repo::list_problems()
{
    //We could pass many different things as a comparison object.
    //In C++11, either an struct with the () operator overloaded, or a lambda.
    //I decided for the latter.     
    auto lamb = [](const Problem& a, const Problem& b)->bool
    {
	double a_r = a.get_ratio(), b_r = b.get_ratio();
	if (a_r < b_r)
	{
	    return true;
	}
	else if (a_r == b_r) 
	{
	    return a.get_id() < b.get_id();
	}
	else return false;
    };

    //In C++11 it is required to pass it on
    //as an argument of the constructor.
    set<Problem, decltype(lamb)> aux_problem_list(lamb);
    for (const auto& problem : this->problem_list)
    {
	aux_problem_list.insert(problem.second);
    }
    for (const auto& problem : aux_problem_list)
    {
	problem.info_problem();
    }
}

Problem_repo::~Problem_repo(){}
