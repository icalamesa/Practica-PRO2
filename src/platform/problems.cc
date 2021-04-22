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

int Problem_list::binary_search(string problem_id)
{

}

bool problem_exists(string problem_id)
{
    return find(problem_list.begin(), problem_list.end(), problem_id) != problem_list.end();
}
