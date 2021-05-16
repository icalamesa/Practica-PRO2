/**
    @file
    @brief Problem class specification.

    @author Ivan Cala Mesa
    @date 15th of May of 2021

*/
using namespace std;
/** @cond */
#include <string>
#include <vector>
/** @endcond */

#ifndef PROBLEM_HH
#define PROBLEM_HH

/** @brief Class that behaves as an uniquely id-identified problem in the Evaluator platform.

  The Problem class allows the platform store insightful use information such as the amount of resolution attempts and successful submissions to uniquely identified problems (by an string id).
*/
class Problem
{
    /** @brief Identifier of Problem.*/
    string id;
    /** @brief Total submissions counter.*/
    int submissions = 0;
    /** @brief Successful submissions counter.*/
    int successful_submissions = 0;
    /** @brief Problem ratio. Result of (submissions+1)/(successful_submissions+1).*/
    double ratio = 1;
    /**
      @brief Ratio recalculator and updater.
      @pre Always true.
      @post Recalculates the ratio variable, and reassigns the result in the proper variable.
    */
    void recalculate_ratio();
    Problem();
    public:
	/**
	    @brief Problem constructor.
	    @param problem_id Is the id for the new problem instance.
	    @pre Always true.
	    @post A problem instance with @p problem_id as its id is created.
	*/
	Problem(const string& problem_id);
	/**
	    @brief Identifier getter.
	    @return Problem id.
	*/
	string get_id() const;
	/**
	    @brief Ratio getter.
	    @return The ratio, whose calculation is as follows: (successful_submissions+1)/(total_submissions+1)
	*/
	double get_ratio() const;
	/**
	    @brief Total submissions counter getter.
	    @return Integer with the number of attempts/total submissions done to this problem.
	*/
	int get_attempts() const;
	/**
	    @brief Successful submissions counter getter.
	    @return Integer with the number of successful attempts/correct submissions done to this problem.
	*/
	int get_solved() const;
        /**
	    @brief Printer of information of the Problem on Standard output.
            @pre Always true.
            @post Information on the problem is displayed on Standard output in the following format:
	    id(total_attempts,total_solved,ratio)
        */
        void info_problem() const;
	/**
	  @brief Submission results counter modifier.
	  @param success Boolean that tells whether the problem submited was correctly solved or not. 
	  @pre Always true.
	  @post Registers that a problem submission has been performed, increases the counter of total attempts performed on it, and if @p success is True, increases the counter of total successful submissions performed with the problem.
	*/
	void problem_submission(bool success);
        bool operator==(const Problem& other) const;
	bool operator<(const Problem& other) const;
	~Problem();

};


#endif
