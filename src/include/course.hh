/**
    @file
    @brief Course class specification.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/
/** @cond */
#include <string>
/** @endcond */

#include "sessions.hh"
using namespace std;

#ifndef COURSE_HH
#define COURSE_HH

/** @brief Repository of @ref Session instances identified by an unique id.

    The Course class behaves as a wrapper of uniquely identified by an id combinations Session instances.
*/
class Course
{
    vector<string> session_list;
    public:
	Course();
	/**
	    @return True if there is no repeated problem across the different sessions stored in the implicit parameter. False otherwise.
	*/
	bool is_legal();
	/**
	    @param target_problem The problem id to be searched.
            @pre @p target_problem is an string correctly formatted. A problem with @p target_problem as an identifier exists.
	    @return An std::string with the id of the internal session that contains the given problem id. If it does not exist, the string returned is empty.
	*/
	string find_session_id(string target_problem);
	/**
	    @param Id String with identifier of a session.
	    @pre Session with @p session_id as an identifier exists.
	    @return Reference to @ref Session instance.
	*/
	Session& get_session(string session_id);
	/**
	    @param session_id Id of the Session instance to search for.
	    @pre No precondition.
	    @return Boolean True if a Session with @p session_id as its identifier exists. False otherwise.
	*/
	bool session_exists(string session_id);
	//reads n sessions, each with their specific id
	void read_course(int n);
	Session& operator[](string);

	~Course();
};



#endif
