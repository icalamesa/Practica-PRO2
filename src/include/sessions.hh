
/**
    @file
    @brief Session_repo list interface specification.

    @author Ivan Cala Mesa
    @date 15th of May of 2021

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
class Session_repo
{
    /** @brief Container of Session instances. Access by identifier. */
    map<string, Session> session_list;
    public:
	Session_repo();	
	/**
	    @brief Session reference getter.
	    @param session_id Valid identifier of an exiting Session instance.
	    @return Lvalue Session instance reference.
	*/
	const Session& get_session(const string& session_id) const;
	/**
	    @brief Const Session reference getter.
	    @param session_id Valid identifier of an exiting Session instance.
	    @return Lvalue Session instance const reference.
	*/
	Session& get_session(const string& session_id);
	/**
	    @brief Session bulk insertion method.

	    Read from standard input a n number, and n sessions are followed, where n>=1.
	    @pre No problems repeat within individual sessions. Standard input follows the format requirements specified by @ref Session methods.
	    @post Read Session instances get inserted into the Session_repo. 
	*/
	void read_sessions();
	/**
	    @brief Session existence checker.
	    @param target Id of Session to search for.
	    @return True if a given Session id exists in the @ref Session list, false otherwise.
	*/
	bool exists_session(const string& target) const;
	/**
	    @brief Session inserter method.
	    @param new_session The already initialized @ref Session instance to be added.
	    @pre Always true.
	    @post Inserts @p new_session onto the list of sessions.
	    @return Boolean True if an insertion actually happened(no identifier overlapping). False otherwise.
	*/
	bool insert_session(const Session& new_session);
	/**
	    @brief Session list size getter.
	    @return Integer with the amount of @ref Session contained in the list.
	*/
	int size();
	/**
	  @brief Prints information of every available Session instance.
            @pre Always true.
            @post Info of all of the contained sessions is displayed on Standard output in the following format:\n
	    id session_size sessions_in_postorder \n
	    id2 session2_size sessions_in_postorder \n
	    ...
	*/
	void list_sessions() const;
	/**
	  @brief Prints information of an specific Session instance.
            @param session_id Id of an specific session.
            @pre @p session_id is the identifier of an existing Session.
            @post Info on the session whose id is @p session_id is displayed on Standard output in the following format:\n
	    id session_size sessions_in_postorder.
	*/
	void list_sessions(const string& session_id) const;
	/**
	*/
	~Session_repo();
};
#endif
