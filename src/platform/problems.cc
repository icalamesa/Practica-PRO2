#include "problems.hh"
#include <algorithm>
#include <iostream>

using namespace std;

void Problem_repo::insert_problem(string problem_id);
{
    this->problem_list.push_back(Problem(problem_id));
}

void Problem_repo::read_problems()
{
    //number of problems
    int n;
    cin >> n;
    //n problem ids are followed.
    for (int i = 0; i < n; i++)
    {
	cin >> problem_id;
	this->insert_problem(problem_id);
    }
}

bool Problem_repo::comp_by_id(const Problem& a, const Problem& b)
{
    return a.get_id() < b.get_id();
}

bool problem_exists(string problem_id)
{
    return find(problem_list.begin(), problem_list.end(), problem_id) != problem_list.end();
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
    sort(this->problem_list.begin(), this->problem_list.end(), Problem_repo::id_sort);
}

void Problem_repo::insert_problem(Problem new_probem)
{
    this->insertion(new_problem);
    sort(this->problem_list.begin(), this->problem_list.end(), Problem_repo::id_sort);
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
    sort(this->problem_list.begin(), problem_list.end(), Problem_repo::id_sort);
}
//we assume the internal list is sorted.
Problem& Problem_repo::get_problem(string problem_id)
{ 
    Problem obj = Problem(problem_id)
    return std::binary_search(this->problem_list.begin(), this->problem_list.end(), obj, 
    [&](Problem a, Problem b)->bool { return a.get_id() < b.get_id() } );
}

