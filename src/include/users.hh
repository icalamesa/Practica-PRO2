/** 
    @file
    @brief Specification of the whole User list/DB general-use interface.
    
    Both @ref User and @ref Users are 'independent' classes in that they do not require any other class to make sense as a whole. In this case, especially the @ref User class is an self-contained class (even its id is inside it).
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
/** @brief General interface to store and access the user list. 

    This class is a generic interface that allows us to create, modify and delete entries for the users that are registered in the Platform. Designed for a dynamic use regardless of the storage model (memory and/or persistent database).
*/
class Users
{
    class User
    {
	public:
	    string id;
	    string coursing; ///< Curs actual cursat per l'usuari, buit si no cursa res
	    int total_successes = 0;
	    int total_attempted = 0;
	    //one of these
	    //map<string, vector<string>> solved;
	    map<string, bool> solved;
	    User();
		/**
		    The constructor of the @ref User class. An id is required for construction. Empty students(no id) do not make sense. Each user is by definition an individual instance with its own self-contained id.
		@param id The id for the new student instance.
		*/
		User(string id);
		~User();
    };

    map<string, User> user_list;
    public:
	/**
	    Constructs an empty Users class.
	*/
	Users();
	/**
	    @param id Id of the specific student to search for.
	    @return An std::string with id of the course that the specific User is enrolled in (at function call).
	*/
	const string tell_course(string id);
	/**
	    @param id Id of the specific student to search for.
	    @return True if the specific User is enrolled in a course, false if it is not.
	*/
	bool is_coursing(string id);

	/**
	    @param id Id of the specific student to search for.
	    @return Integer with the amount of attempts(deliveries) the specific User has performed onto the platform.
	*/
	const int attempts(string id);
	/**
	    @param id Id of the specific student to search for.
	    @return Integer with the amount of problems that have been solved so far by the specific User (deliveries flagged as correct). 
	*/
	const int amount_solved_problems(string id);
	/**
	    @param id of the specific student to search for.
	    @return Integer with the amount of different problems that have been attempted so far by the specific User.
	*/
	const int different_attempts(string id);
	//if empty string, empty course

	/**
	    Enrolls the specific User in a course if it is not in one (at function call). Prints an error message if it is already enrolled in a course.
	    @param id Id of the specific student to search for.
	    @param course_name Name of the course to enroll the user in.
	    @pre An @p id of an existing user not enrolled in any course, plus the id of an existing @ref Course instance in the valid Course container.
	    @post User with @p id identifier has been enrolled in a course with @p course_name identifier. 

	*/
	void sign_in_course(string id, int course_name);
	/**
	    @param id Id of the specific student to search for.
	    @param problem_id The id of the newly solved problem
	    @param solved True if the given problem is solved, false otherwise.
	    @pre Problem with @p problem_id identifier exists in the platform and has not been already solved by the user with the given @p id. 
	    @post Registers a problem to the list of attempted problems by the user. Specifies whether the problem is solved and allows modification of the state of the problem (has been solved).
	*/
	void add_problem_to_list(string id, string problem_id, bool solved);
	/**
	    @param id Id of the specific student to search for.
	    @pre No precondition required.
	    @post The list of solved problems is blanked out.
	*/
	void restart_solved_list();
	/**
	    @param id Id of the specific student to search for.
	    @pre User with @p id identifier does not already exist in the platform.
	    @post User with the @p id identifier has been added to the user list.
	*/
	void insert_user(string id);
	/**
	    @param id Id of the specific student to search for.
	    @pre User with @p id identifier exists in the platform.
	    @post User with @p id identifier no longer exists in the platform.
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
