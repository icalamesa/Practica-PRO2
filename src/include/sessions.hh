
/** 
    @file
    @brief Session class and the session list interface.
    
    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/

/** @cond */
#include <set>
#include <map>
#include "BinTree.hh"
/** @endcond */

#include "problems.hh"

using namespace std;
#ifndef SESSIONS_HH
#define SESSIONS_HH
/** @brief Class that behaves as a problem set with completion requisites.

    Class that represent a session, composed of multiple problems. A system of prerequisites is implemented so that problems may require other problems to be resolved first.
*/
class Session
{
    BinTree<string> problem_node;
    int size = 0;
    void recalc_size();

    public:
	Session();
	/**
	    Reads problems from standard input to initialize the implicit parameter.
	*/
	void read_session();
	/**
	    @return A std::set<std::string> containing the id of the problems contained in the implicit parameter.
	*/
	set<string> list_of_problems();
	/**
	    @return True if the target problem id is found in this session problem list. False otherwise. 
	*/
	bool find(string target_problem);
	
	~Session();
};
/** @brief General interface to manage a Session repository. 

    Repository of @ref Session instances that works as a general interface between the (implementation-agnostic) Session storage model and the caller.
*/
class Sessions
{
    map<string, Session> session_list;

    public:
	Sessions();
	/**
	    @param session_id The id of the specific session.
	    @return Returns an std::set<string> of ids of problems in a given session.
	*/
	set<string> list_of_problems(string session_id);
	/**
	    Reads @ref Session instances from standard input and inserts them onto the list of sessions.
	*/
	void read_sessions();
	/**
	    @return An std::string with the id of the specific session that contains a given problem id. Blank string if no matches.
	*/
	string find_in_sessions(string prob);
	/**
	    @return True if a given Session id exists in the @ref Session list, false otherwise.
	*/
	bool exists_session(string target);
	/**
	    Inserts session onto the list of sessions.
	    @param id The id for the new session.
	    @param new_session The already initialized @ref Session instance to be added.
	*/
	void insert_session(string id, Session new_session);
	/**
	    @return Integer with the amount of @ref Session contained in the list.
	*/
	int size();

	~Sessions();
};
#endif
