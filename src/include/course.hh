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
    Sessions session_list;
    public:
	Course();
	/**
	    @return True if there is no repeated problem across the different sessions stored in the implicit parameter. False otherwise.
	*/
	bool is_legal();
	/**
	    @param target_problem The problem id to be searched.
        @pre @p target_problem is an string correctly formatted
	    @return An std::string with the id of the internal session that contains the given problem id. If it does not exist, the string returned is empty.
	*/
	string find_session_id(string target_problem);
	/**
        @param id String with identifier of a session
        @return Reference to @ref Session instance.
	*/
	Session& get_session(string id);
	Session& operator[](string);

	~Course();
};



#endif
