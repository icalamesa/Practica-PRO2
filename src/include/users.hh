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
#include "user.hh"
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
	User& user_find(const string& user_id);
	void list_users(decltype(user_list)::const_iterator& it) const;
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
	User& get_user(const string& user_id);
	/**
	    @param user_id is the id of the User whose existence is supposed to be found.
	    @pre @p user_id size is greater than zero. 
	    @return True if a User with the given identifier exists, false otherwise.
	*/
	bool user_exists(const string& user_id);
	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero. User with @p user_id as identifier exists.
	    @post If a @ref User instance with the given identifier exists, an integer with id of the course that the specific User is enrolled in is returned. The returned integer is set to 0 otherwise. If a @ref User instance with the given identifier does not exist, an error is printed in the Standard output.
	*/
	int tell_course(const string& id);
	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero. User with @p id as identifier exists.
	    @return True if the specific User is enrolled in a course, false if it is not.
	*/
	bool is_coursing(const string& id);

	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero. @p id belongs to an existing user.
	    @return Integer with the amount of attempts(deliveries) the specific User has performed onto the platform.
	*/
	int amount_attempts(const string& id);
	/**
	    @param id Id of the specific student to search for.
	    @pre @p id size is greater than zero. @p id belongs to an existing user.
	    @return Integer with the amount of problems that have been solved so far by the specific User (deliveries flagged as correct). 

	*/
	int amount_solved_problems(const string& id);
	/**
	    @param id of the specific student to search for.
	    @pre @p id size is greater than zero. @p id belongs to an existing user.
	    @return Integer with the amount of different problems that have been attempted so far by the specific User with the given id. If it does not exist, an error message is printed.
	*/
	int different_attempts(const string& id);
	//if empty string, empty course

	/**
	    Enrolls the specific User in a course if it is not in one (at function call). Prints an error message if it is already enrolled in a course.
	    @param id Id of the specific student to search for.
	    @param course_name Name of the course to enroll the user in.
	    @pre @p id is the identifier of an existing user that is not enrolled in any course, plus @p course_id string corresponds to the id of an existing @ref Course instance in the valid Course container.
	    @post User with @p id identifier has been enrolled in a course with @p course_name identifier. 

	*/
	//CORREGIR
	void sign_in_course(const string& id, int course_name, Sessions& session_list, Courses& course_list);
	/**
	    @param id Id of the specific student to search for.
	    @param problem_id The id of the newly solved problem
	    @param solved True if the given problem is solved, false otherwise.
	    @pre @p problem_id string corresponds to the identifier of an existing problem in the platform that has not already been solved by the user with the given @p id as string id. 
	    @post Registers a problem to the list of attempted problems by the user. Specifies whether the problem is solved and allows modification of the state of the problem (has been solved).
	*/
	void add_problem_to_list(const string& id, const string& problem_id, bool solved);
	/**
	    @param user_id Id of the User instance to search for.
	    @pre User with the @p user_id identifier exists. If it is coursing a @ref Course, that Course must exist in the @ref Course list.
	    @post Lists in increasing order by identifier the problems that the user has not yet solved in the course in which he is currently enrolled, but to which he can already make a submission (because he fulfills all his prerequisites, direct and indirect). In addition to the identifiers, the number of submissions made by the user to each problem in the list (value greater than or equal to zero) is also printed in Standard output. 	
	*/
	void list_solvable_problems(const string& user_id);
	/**
	    @param user_id Id of the User instance to search for.
	    @pre User with @p user_id identifier exists.
	    @post The problems successfully solved by the user are listed in increasing order by identifier, either in the course he/she is currently enrolled in (if any) or those solved in previous courses. In addition to the identifiers, the number of submissions made by the user to each problem in the list (value greater than or equal to one) is also printed.
	*/
	void list_solved_problems_by(const string& user_id);
	/**
	    @param id Id of the specific student to search for.
	    @pre No precondition.
	    @post The list of solved problems is blanked out.
	*/
	void restart_solved_list(const string& id);
	/**
	    @param user_id Id of the specific student to search for.
	    @pre @p id size is greater than zero.
	    @post If User with @p id identifier did not exist previously, it gets added to the user list and the number of Users after the inclusion is printed. If it did exist, an error message is printed in the standard output.
	*/
	void insert_user(const string& user_id);
	/**
	    @param user_id Id of the specific student to search for.
	    @pre @ref User with @p id identifier exists. @p id size is greater than zero.
	    @post If a User with @p id identifier existed, it no longer does and the number of Users after the inclusion is printed.	
	*/
	bool remove_user(const string& user_id, Courses& course_list);
	/**
	    @return Integer with the size of the currently registered user list.
	*/
	int size();
	/**
	    @pre The implicit parameter has not been initialized.
	    @post Read user identifiers from standard input have been created and inserted into the platform.
	*/
	void read_users();
        /**
            @pre No precondition
            @post Information of all of the existing User instances contained in the implicit parameter is displayed on Standard output.
        */
        void list_users() const;
	void list_users(const string& user_id) const;
	//void push_problem(const string& user_id, const string& problem_id);
	/**
	    Destructs the list of Users.
	*/
	void push_problems_from_sessions(const string& user_id, int course_id, Sessions& session_list, Courses& course_list);

	void deliver_problem(const string& user_id, const string& problem_id, bool success, Sessions& session_list, Courses& course_list);

	~Users();
};
#endif
