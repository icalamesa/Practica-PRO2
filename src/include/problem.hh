/**
    @file
    @brief Problem class specification.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/
using namespace std;
/** @cond */
#include <string>
#include <vector>
/** @endcond */

#ifndef PROBLEM_HH
#define PROBLEM_HH

/** @brief Class that behaves as an uniquely id-identified problem in the Evaluator platform.

  The Problem class allows the platform store insightful use information such as the amount of resolution attempts and successful deliveries to uniquely identified problems (by an string id).
*/
class Problem
{
    string id;
    int deliveries = 0;
    int successful_deliveries = 0;
    double ratio = 1;
    void recalculate_ratio();
    Problem();
    public:
	/**
	    @ref Problem constructor.
	    @param problem_id Is the id for the new problem instance.
	    @pre No precondition.
	    @post A problem instance with @p problem_id as its id is created.
	*/
	Problem(const string& problem_id);
	/**
	    @return Problem id.
	*/
	string get_id() const;
	/**
	    @return The ratio, whose calculation is as follows: (successful_deliveries+1)/(total_deliveries+1)
	*/
	double get_ratio() const;
	/**
	    @return Integer with the number of attempts/total deliveries done to this problem.
	*/
	int get_attempts() const;
	/**
	    @return Integer with the number of successful attempts/correct deliveries done to this problem.
	*/
	int get_solved() const;
        /**
            @pre No precondition.
            @post Information on the problem is displayed on Standard output
        */
        void info_problem() const;
	void problem_delivery(bool sucess);
        bool operator==(const Problem& other) const;
	bool operator<(const Problem& other) const;
	~Problem();

};


#endif
