#include "problems.hh"
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

Problem_repo::Problem_repo(){}

bool Problem_repo::comp_by_id(const Problem& a, const Problem& b)
{
    return a.get_id() < b.get_id();
}

bool Problem_repo::comp_by_ratio(const Problem& a, const Problem& b)
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
}

//template <class comp>
//void Problem_repo::sort_problem_list(comp foo)
//{
    //this->problem_list.sort(foo);
//}

bool Problem_repo::problem_exists(const string& problem_id)
{
    return this->problem_list.find(problem_id) != this->problem_list.end();
}

int Problem_repo::size()
{
    return problem_list.size();
}

//void Problem_repo::insertion(Problem new_problem)
//{
    //this->problem_list.insert(make_pair(new_problem);
//}

void Problem_repo::insert_problem(const string& problem_id)
{
    this->problem_list.insert(make_pair(problem_id, Problem(problem_id)));
}

//void Problem_repo::insert_problem(Problem new_problem)
//{
    //this->insertion(new_problem);
//}

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
//we assume the internal list is sorted.
Problem& Problem_repo::get_problem(const string& problem_id)
{ 
    //Problem obj = Problem(problem_id);
    //return *( std::find(this->problem_list.begin(), this->problem_list.end(), obj) );
    return this->problem_list.find(problem_id)->second;
}

void Problem_repo::list_problems()
{
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
