
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
	/**
	    @ref Problem constructor.
	    @param problem_id Is the id for the new problem instance.
	    @pre No precondition.
	    @post A problem instance with @p problem_id as its id is created.
	*/
	Problem(string problem_id);
	/**
	    @return Problem id.
	*/
	string get_id();
	/**
	    @return The ratio, whose calculation is as follows: (successful_deliveries+1)/(total_deliveries+1)
	*/
	double get_ratio();
	/**
	    @return Integer with the number of attempts/total deliveries done to this problem.
	*/
	int get_attempts();
	/**
	    @return Integer with the number of successful attempts/correct deliveries done to this problem.
	*/
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
    void ratio_sort();
    void id_sort();

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
	    @post Returns a problem reference to the problem belonging to the given index. Prints error message if such a problem does not exist
	*/
	Problem& get_problem(int index);
	~Problem_repo();
};
#endif
