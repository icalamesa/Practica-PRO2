/** 
    @file
    @brief User class specification.
    @author Ivan Cala Mesa
    @date 1st of april of 2021
*/
/** @cond */
#include <string>
#include <map>
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
    int coursing; ///< Curs actual cursat per l'usuari, buit si no cursa res
    int total_successes = 0;
    int total_attempted = 0;
    //one of these
    //map<string, vector<string>> solved;
    map<string, bool> solved;
    public:
	//CONSULTORES

	/**
	    The constructor of the @ref User class. 
	*/
	User();
	/**
	    @pre No precondition.
	    @post If the user is enrolled in a course, the id of the course is returned. If it is not, the returned integer is set to 0.
	*/
	const int u_tell_course();
	/**
	    @pre No precondition.
	    @return True if the specific User is enrolled in a course, false otherwise.
	*/
	bool u_is_coursing();
	/**
	    @pre No precondition.
	    @return Integer with the amount of attempts(deliveries) the specific User has performed onto the platform.
	*/
	const int u_amount_attempts();
	/**
	    @pre No precondition.	
	    @return Integer with the amount of problems that have been solved so far by the specific User (deliveries flagged as correct). 
	*/
	const int u_amount_solved_problems();
	/**
	    @pre No precondition.
	    @return Integer with the amount of different problems that have been attempted so far by the specific User.
	*/
	const int u_different_attempts();
	//if empty string, empty course

	//MODIFICADORES

	/**
	    Enrolls the specific User in a course if it is not in one (at function call). Prints an error message if it is already enrolled in a course.
	    @param course_name Name of the course to enroll the user in.
	    @pre @p course_name integer corresponds to the id of an existing @ref Course instance in the valid Course container.
	    @post If the user was not enrolled in a course, it is then enrolled in one with @p course_name identifier. If it already was enrolled in a @ref Course, prints an error message. 

	*/
	void u_sign_in_course(int course_name);
	/**
	    @param problem_id The id of the newly solved problem
	    @param solved True if the given problem is solved, false otherwise.
	    @pre @p problem_id string corresponds to the identifier of an existing problem in the platform that has not already been solved by the user with the given @p id as string id. The @p problem_id identifier corresponds to a problem that the user can solve(because he belongs to a course with it, and it is a solvable problem).
	    @post Registers a problem to the list of attempted problems by the user. Specifies whether the problem is solved and allows modification of the state of the problem (has been solved). If the problem delivery completes the list of problems of a Course, User stops being enrolled to it.
	*/
	void u_add_problem_to_list(string problem_id, bool solved);
	/**
	    @pre No precondition.
	    @post The list of solved problems by the implicit parameter is blanked out.
	*/
	void u_restart_solved_list();
	/**
            @pre No precondition.
            @post Information of the User is displayed on Standard output.
        */ 
	~User();
};


#endif
