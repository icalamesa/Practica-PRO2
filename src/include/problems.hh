
/**
    @file
    @brief Problem repository interface specification.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/
using namespace std;
/** @cond */
#include <string>
#include <vector>
/** @endcond */

#include "problem.hh"

#ifndef PROBLEMS_HH
#define PROBLEMS_HH

/** @brief General interface for a repository of Problem instances.

  The Problem_repo class acts as an implementation-agnostic interface between the caller and the internal implementation of the problems of the Evaluator platform.
  It allows us to keep track of non-removable problem entries(and its correspondent associated data).
*/
class Problem_repo
{
    static bool comp_by_ratio(const Problem& a, const Problem& b);
    static bool comp_by_id(const Problem& a, const Problem& b);
    vector<Problem> problem_list;
    void ratio_sort();
    void id_sort();
    int binary_search(string problem_id);

    void insert_problem_no_sort(string problem_id);

    void insertion(Problem new_problem);

    public:
	Problem_repo();
    /**
        @return Integer with the size of the problem repository.
    */
	int size();
    /**
        @param new_problem is the Problem instance to be inserted.
        @pre @p new_problem is a valid problem instance.
        @post @p new_problem has been inserted to the problem repository.
    */
	void insert_problem(Problem new_problem);
    /**
        @param id The id of the new problem to be created and added to the problem repository.
        @pre @p id size is greater than zero.
        @post if @p id does not exist, it is added to the problem repository. Otherwise throws error in Standard output.
    */
	void insert_problem(string id);
    /**
        Method that reads an integer n, and n strings(problem ids) are followed.
        @pre Standard input follows the format.
        @post Problem instances read from standard input have been inserted into the list.
    */
	void read_problems();
	/**
	    @pre Problem with the given @p problem_id exists.
	    @post Returns a problem reference to the problem belonging to the given index. Prints error message if such a problem does not exist
	*/
	Problem& get_problem(string problem_id);
	/**
	    @pre No precondition.
	    @return Boolean True if a Problem with @p problem_id exists. False otherwise.
	*/
	bool problem_exists(string problem_id);
	~Problem_repo();
};
#endif
