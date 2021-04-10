/** 
    @file
    @brief Specification of the whole User list/DB general-use interface.
    @author Ivan Cala Mesa
    @date 1st of april of 2021

*/
/** @cond */
#include <string>
#include <vector>
#include <map>
/** @endcond */

using namespace std;
#ifndef USERS_HH
#define USERS_HH


    /** @class Users
	@brief General interface to store and access the user list. 

	This class is a generic interface that allows us to create, modify and delete entries for the users that are registered in the Platform. Designed for a dynamic use regardless of the storage model (memory and/or persistent database).
    */
    class Users
    {
	map<string, User> user_list;
	public:
	    /**
		Constructs an empty Users class.
	    */
	    Users();
	    /**
		@param user_id Id of the user to be searched for.
		@pre @p id size is greater than zero. User with @p user_id as identifier exists.
		@return Reference to @ref User instance that fulfills the id requirement.
	    */
	    User& get_user(string user_id);
	    /**
		@param user_id is the id of the User whose existence is supposed to be found.
		@pre @p user_id size is greater than zero.
		@return True if a User with the given identifier exists, false otherwise.
	    */
	bool user_exists(string user_id);
	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero.
	    @post If a @ref User instance with the given identifier exists, an integer with id of the course that the specific User is enrolled in is returned. The returned integer is set to 0 otherwise. If a @ref User instance with the given identifier does not exist, an error is printed in the Standard output.
	*/
	const int tell_course(string id);
	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero.
	    @return True if the specific User is enrolled in a course, false if it is not.
	*/
	bool is_coursing(string id);

	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero. @p id belongs to an existing user.
	    @return Integer with the amount of attempts(deliveries) the specific User has performed onto the platform.
	*/
	const int amount_attempts(string id);
	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero. @p id belongs to an existing user.
	    @return Integer with the amount of problems that have been solved so far by the specific User (deliveries flagged as correct). 

	*/
	const int amount_solved_problems(string id);
	/**
	    @param id of the specific student to search for.
	    @pre @p id size is greater than zero. @p id belongs to an existing user.
	    @return Integer with the amount of different problems that have been attempted so far by the specific User with the given id. If it does not exist, an error message is printed.
	*/
	const int different_attempts(string id);
	//if empty string, empty course

	/**
	    Enrolls the specific User in a course if it is not in one (at function call). Prints an error message if it is already enrolled in a course.
	    @param id Id of the specific student to search for.
	    @param course_name Name of the course to enroll the user in.
	    @pre @p id is the identifier of an existing user that is not enrolled in any course, plus @p course_id string corresponds to the id of an existing @ref Course instance in the valid Course container.
	    @post User with @p id identifier has been enrolled in a course with @p course_name identifier. 

	*/
	void sign_in_course(string id, int course_name);
	/**
	    @param id Id of the specific student to search for.
	    @param problem_id The id of the newly solved problem
	    @param solved True if the given problem is solved, false otherwise.
	    @pre @p problem_id string corresponds to the identifier of an existing problem in the platform that has not already been solved by the user with the given @p id as string id. 
	    @post Registers a problem to the list of attempted problems by the user. Specifies whether the problem is solved and allows modification of the state of the problem (has been solved).
	*/
	void add_problem_to_list(string id, string problem_id, bool solved);
	/**
	    @param id Id of the specific student to search for.
	    @pre No precondition.
	    @post The list of solved problems is blanked out.
	*/
	void restart_solved_list(string id);
	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero.
	    @post If User with @p id identifier did not exist previously, it gets added to the user list and the number of Users after the inclusion is printed. If it did exist, an error message is printed in the standard output.
	*/
	void insert_user(string id);
	/**
	    @param id Id of the specific student to search for.
	    @pre Size of the problem_repo instance is not 0. @p id size is greater than zero.
	    @post If a User with @p id identifier existed, it no longer does and the number of Users after the inclusion is printed. If it didn't exist, an error message is printed in the standard output.
	*/
	void remove_user(string id);
	/**
	    @return Integer with the size of the currently registered user list.
	*/
	int size();
	/**
	    Destructs the list of Users.
	*/
	~Users();
};
#endif
