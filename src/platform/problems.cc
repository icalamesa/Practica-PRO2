#include "problems.hh"
#include <algorithm>
#include <iostream>

using namespace std;

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

template <class comp>
void Problem_repo::sort_problem_list(comp foo)
{
    this->problem_list.sort(foo);
}

bool Problem_repo::problem_exists(string problem_id)
{
    return std::binary_search(
	    this->problem_list.begin(), 
	    this->problem_list.end(), 
	    Problem(problem_id),
	    std::less<Problem>{});
}

int Problem_repo::size()
{
    return problem_list.size();
}

void Problem_repo::insertion(Problem new_problem)
{
    this->problem_list.push_back(new_problem);
}

void Problem_repo::insert_problem(string problem_id)
{
    this->insertion(Problem(problem_id));
    this->sort_problem_list(std::less<Problem>{});
}

void Problem_repo::insert_problem(Problem new_problem)
{
    this->insertion(new_problem);
    this->sort_problem_list(std::less<Problem>{});
}

void Problem_repo::read_problems()
{
    int n;
    cin >> n;
    string problem_id;
    for (int i = 0; i < n; i++)
    {
        cin >> problem_id;
        this->insertion(problem_id);
    }
    this->sort_problem_list(std::less<Problem>{});
}
//we assume the internal list is sorted.
Problem& Problem_repo::get_problem(string problem_id)
{ 
    Problem obj = Problem(problem_id);
    return *( std::find(this->problem_list.begin(), this->problem_list.end(), obj) );
}

void Problem_repo::list_problems()
{
    this->sort_problem_list(Problem_repo::comp_by_ratio);
    for (const auto& problem : this->problem_list)
    {
	problem.info_problem();
    }
    this->sort_problem_list(std::less<Problem>{});
}
