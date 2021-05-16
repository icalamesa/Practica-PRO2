
/**
    @file
    @brief Problem repository interface specification.

    @author Ivan Cala Mesa
    @date 15th of May of 2021

*/
using namespace std;
/** @cond */
#include <string>
#include <list>
#include <map>
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
    /** @brief Container of the Problem instances. Access by string id.*/
    map<string, Problem> problem_list;

    public:
	Problem_repo();
	/**
	    @brief Problem Lvalue reference getter.
	    @pre Problem with the given @p problem_id exists.
	    @post Returns a problem reference to the problem belonging to the given index. Prints error message if such a problem does not exist
	*/
	Problem& get_problem(const string& problem_id);
	/** 
	    @brief Problem Lvalue const reference getter.
	    @pre Problem with the given @p problem_id exists.
	    @post Returns a problem reference to the problem belonging to the given index. Prints error message if such a problem does not exist
	*/
	const Problem& get_problem(const string& problem_id) const;
	/**
	    @brief Container size getter.
	    @return Integer with the size of the problem repository.
	*/
	int size();
	/**
	  @brief Problem inserter.
	    @param new_problem is the Problem instance to be inserted.
	    @pre @p new_problem is a valid problem instance.
	    @post @p new_problem has been inserted to the problem repository.
	*/
	void insert_problem(Problem new_problem);
	/**
	  @brief Problem inserter(constructed inside).
	    @param id The id of the new problem to be created and added to the problem repository.
	    @pre @p id size is greater than zero.
	    @post if @p id does not exist, it is added to the problem repository. Otherwise throws error in Standard output.
	*/
	bool insert_problem(const string& id);
	/**
	    @brief Inserter of multiple Problem instances read from Standard input.
	    Method that reads an integer n, and n strings(problem ids) are followed.
	    @pre Standard input follows the format.
	    @post Problem instances read from standard input have been inserted into the list.
	*/
	void read_problems();
	/**
	    @brief Problem existence checker (by id).
	    @pre Always true.
	    @return Boolean True if a Problem with @p problem_id exists. False otherwise.
	*/
	bool problem_exists(const string& problem_id);
	/**
	  @brief Printer of information of every problem in the container. 
	  @pre No precondition.
	  @post The problems in the collection are listed, indicating for each problem the number of total submissions and the number of successful submissions to that problem, in both cases from present or past users. The ratio (successful_submissions+ 1)/(total_submissions+ 1) should also be written, and the problems should be listed in increasing order by this ratio. In case of a tie, they should be listed in increasing order of identifier.

	*/
	void list_problems();
	/**
	  @brief Destructor.
	*/
	~Problem_repo();
};
#endif
