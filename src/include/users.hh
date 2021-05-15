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


    /** @class User_repo
	@brief General interface to store and access the user list. 

	This class is a generic interface that allows us to create, modify and delete entries for the users that are registered in the Platform. Designed for a dynamic use regardless of the storage model (memory and/or persistent database).
    */
    class User_repo
    {
	map<string, User> user_list;
	User& user_find(const string& user_id);
	void list_users(decltype(user_list)::const_iterator& it) const;
	public:
	/**
	    Constructs an empty User_repo class.
	*/
	User_repo();
	/**
	    @param user_id Id of the user to be searched for.
	    @pre @p id size is greater than zero. User with @p user_id as identifier exists.
	    @return Reference to @ref User instance that fulfills the id requirement.
	*/
	User& get_user(const string& user_id);
	const User& get_user(const string& user_id) const;
	/**
	    @param user_id is the id of the User whose existence is supposed to be found.
	    @pre @p user_id size is greater than zero. 
	    @return True if a User with the given identifier exists, false otherwise.
	*/
	bool user_exists(const string& user_id);
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
	    @param user_id Id of the specific student to search for.
	    @pre @p id size is greater than zero.
	    @post If User with @p id identifier did not exist previously, it gets added to the user list and the number of User_repo after the inclusion is printed. If it did exist, an error message is printed in the standard output.
	*/
	void insert_user(const string& user_id);
	/**
	    @param user_id Id of the specific student to search for.
	    @pre @ref User with @p id identifier exists. @p id size is greater than zero.
	    @post If a User with @p id identifier existed, it no longer does and the number of User_repo after the inclusion is printed.	
	*/
	//EDIT
	pair<bool, int> remove_user(const string& user_id);
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
            @pre Always true
            @post Information of all of the existing User instances contained in the implicit parameter is displayed on Standard output.
        */
        void list_users() const;
	void list_users(const string& user_id) const;
	//void push_problem(const string& user_id, const string& problem_id);
	/**
	    Destructs the list of User_repo.
	*/
	~User_repo();
};
#endif
