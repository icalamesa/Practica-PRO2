/** 
    @file
    @brief User class specification.
    @author Ivan Cala Mesa
    @date 1st of april of 2021
*/
/** @cond */
#include <string>
#include <map>
#include <set>
#include <utility>
/** @endcond */

using namespace std;

#ifndef USER_HH
#define USER_HH

/**
    @class User
    @brief The User class that stores the information for every user in different instances.
*/
class User
{
    /** @brief Integer that represents the currently coursing Course identifier. 0 if not coursing any.*/
    int coursing = 0; //0 if not coursing anything
    /** @brief Total successful deliveries counter.*/
    int total_successes = 0;
    /** @brief Total deliveries attempted counter.*/
    int total_attempted = 0;
    //one of these
    /** @brief List of solvable problems by the User. Theoretically empty if not coursing anything.*/
    set<string> solvable;
    /** @brief Register of the different attempted problems. The key represents the problem identifier. The value is a std::pair of a Boolean (whether the problem has been solved) and an integer (total amount of deliveries performed onto that specific problem).*/
    map<string, pair<bool, int>> problem_register;
    /**
	@brief Generic insertion method into the register of attempted problems.
	@param problem_id Id of a problem.
	@param solved Boolean that tells whether the problem has been solved or not.
	@pre @p problem_id had not been attempted before(not isnerted).
	@post The given @p problem_id has been inserted in the list of at least attempted problems, along with information on whether it has been solved or not.
    */
    void insertion(const string& problem_id, bool solved);
    public:
	//CONSULTORES

	/**
	    The constructor of the @ref User class. 
	*/
	User();
	/**
	  @brief Getter of the currently coursing Course by the User. 0 if not coursing any.
	    @pre Always true.
	    @post If the user is enrolled in a course, the id of the course is returned. If it is not, the returned integer is set to 0.
	*/
	int u_tell_course() const;
	/**
	  @brief Checker of the coursing status(coursing or not).
	    @pre Always true.
	    @return True if the specific User is enrolled in a course, false otherwise.
	*/
	bool u_is_coursing() const;
	/**
	  @brief Getter of the counter of attempted deliveries thus far.
	    @pre Always true.
	    @return Integer with the amount of attempts(deliveries) the specific User has performed onto the platform.
	*/
	int u_amount_attempts() const;
	/**
	  @brief Getter of the counter of successful deliveries thus far.
	    @pre Always true.	
	    @return Integer with the amount of problems that have been solved so far by the specific User (deliveries flagged as correct). 
	*/
	int u_amount_solved_problems() const;
	/**
	  @brief Getter of the amount of different problems where at least one delivery has been performed onto by the User thus far.
	    @pre Always true.
	    @return Integer with the amount of different problems that have been attempted so far by the specific User.
	*/
	int u_different_attempts() const;
	//if empty string, empty course

	//MODIFICADORES

	/**
	    @brief Updates the register of what Course is the User coursing. Does not update anything else. 	    
	    @param course_id Name of the course to enroll the user in.
	    @pre @p course_name integer corresponds to the id of an existing @ref Course instance in the valid Course container. User was not enrolled in any course previously.
	    @post If the user was not enrolled in a course, it is then enrolled in one with @p course_name identifier. If it already was enrolled in a @ref Course, prints an error message. 

	*/
	void u_sign_in_course(int course_id);
	/**
	    @pre Always true.
	    @post The list of solved problems by the implicit parameter is printed in standard output following the format:
	    problem_id(total_attempts)
	    One line for each.
	*/
	void u_list_solved() const;
	/**
	*/
	void u_list_solvable() const;
	/**
	*/
	void info_user() const;
	/**
	  @brief Individually push problems to be solved into the solvable list.
	  @param problem_id Id of a Problem instance.
	  @pre User is enrolled in a Course. @p problem_id belongs to a Session instance that composes the Course the User is enrolled in.
	  @post Problem identifier hgas been pushed into the list of solvable problems.
	*/
	void insert_solvable(const string& problem_id);
	/**
	*/
	void u_deliver_problem(const string& problem_id, bool success);
	/**
	  @brief Checker of whether a problem ahs been solved by the User.
	  @pre Always true.
	  @return Boolean True if it was solved before, False otherwise.
	*/
	bool u_has_solved_problem(const string& problem_id) const;
	/**
	  @brief Checks the pending-to-solve problem list and unenrolls the User if no problem is left to be solved.

	  We assume the correctness of the algorithm that updates the list of solvable problems after signing in a Course and after each delivery.
	  @pre Always true.
	  @post If no problems are left to be solved, unenrolls the User from the Course.
	  @return True if The User has been unerolled. False otherwise.
	*/
	bool u_update_course();
	/**
	*/
	~User();
};


#endif
