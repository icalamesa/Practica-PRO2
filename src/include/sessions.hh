
/**
    @file
    @brief Sessions list interface specification.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/
using namespace std;
/** @cond */
#include <set>
#include <list>
#include <map>
/** @endcond */

#include "session.hh"

#ifndef SESSIONS_HH
#define SESSIONS_HH
/** @brief General interface to manage a Session repository.

    Repository of @ref Session instances that works as a general interface between the (implementation-agnostic) Session storage model and the caller.
*/
class Sessions
{
    map<string, Session> session_list;
    set<string> list_of_problems(string session_id);
    public:
	Sessions();	
	/**
	    @param id Valid identifier of an exiting Session instance.
	    @return Session instance reference
	*/
	const Session& get_session(const string& id) const;
	/**
	*/
	Session& get_session(const string& session_id);
	/**
	    Reads n sessions, where n>=1, from standard input.
	    @pre The implicit parameter is empty (no sessions in it). It has not been initialized before. No problems repeat within individual sessions. Standard input follows the format requirements.
	    @post Read problems get inserted into the Session. 
	*/
	void read_sessions();
	/**
	    @return An std::string with the id of the specific session that contains a given problem id. Blank string if no matches.
	*/
	string find_in_sessions(const string& prob) const;
	/**
	    @return True if a given Session id exists in the @ref Session list, false otherwise.
	*/
	bool exists_session(const string& target) const;
	/**
	    Inserts session onto the list of sessions.
	    @param id The id for the new session.
	    @param new_session The already initialized @ref Session instance to be added.
	*/
	bool insert_session(const Session& new_session);
	bool insert_session(const string& session_id);
	/**
	    @return Integer with the amount of @ref Session contained in the list.
	*/
	int size();
	/**
	*/
	void list_sessions() const;
	/**
	*/
	void list_sessions(const string& session_id) const;
	/**
	*/
	~Sessions();
};
#endif
