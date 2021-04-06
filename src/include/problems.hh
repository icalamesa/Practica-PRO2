
/** 
    @file
    @brief Problem class and a problem repository interface.
    
    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/

/** @cond */
#include <string>
#include <vector>
/** @endcond */
using namespace std;

#ifndef PROBLEMS
#define PROBLEMS

/** @brief Class that behaves as an uniquely id-identified problem in the Evaluator platform.

  The Problem class allows the platform store insightful use information such as the amount of resolution attempts and successful deliveries to uniquely identified problems (by an string id).
*/
class Problem
{
    string id;
    int deliveries = 0;
    int successful_deliveries = 0;
    Problem();
    public:
	Problem(string);

	string get_id();
	double get_ratio();
	int get_attempts();
	int get_solved();
	~Problem();

};
/** @brief General interface for a repository of @ref Problem instances.

  The Problem_repo class acts as an implementation-agnostic interface between the caller and the internal implementation of the problems of the Evaluator platform.
  It allows us to keep track of non-removable problem entries(and its correspondent associated data).
*/
class Problem_repo
{
    static bool comp_by_ratio(const Problem& a, const Problem& b);
    static bool comp_by_id(const Problem& a, const Problem& b);
    vector<Problem> problem_list;
    
    public:
	Problem_repo();

	int size();
	void insert_problem(Problem);
	void insert_problem(string id);
	void insert_problems(const vector<string>& v);
	void read_problems();
	void ratio_sort();
	void id_sort();
	Problem& operator[](int);
	~Problem_repo();
};
#endif
