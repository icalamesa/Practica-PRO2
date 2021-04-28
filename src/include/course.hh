/**
    @file
    @brief Course class specification.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/
/** @cond */
#include <string>
#include <set>
#include <vector>
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
    set<string> session_list_ordered;
    int are_coursing = 0;
    void insertion(const string& ses);
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
	bool find_session_in_course(string target_session) const;
	/**
	    @param session_id Id of the Session instance to search for.
	    @pre No precondition.
	    @return Boolean True if a Session with @p session_id as its identifier exists. False otherwise.
	*/
	bool session_exists(string session_id);
	//reads n sessions, each with their specific id
	void read_course();
	void info_course() const;
	
	int users_coursing() const;
	void increase_coursing();
	void decrease_coursing();

	~Course();
};



#endif
