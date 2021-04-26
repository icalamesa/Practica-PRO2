
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
    list<Session> session_list;
    set<string> list_of_problems(string session_id);
    static bool comp_by_id(const Session& a, const Session& b);
    /**
	Reads @ref Session instances from standard input and inserts them onto the list of sessions(read in preorder).
    */
    void insertion(const Session& new_session);
    void sort_session_list();
    public:
	Sessions();	
	/**
	    Reads n sessions, where n>=1, from standard input.
	    @pre The implicit parameter is empty (no sessions in it). It has not been initialized before. No problems repeat within individual sessions. Standard input follows the format requirements.
	    @post Read problems get inserted into the Session. 
	*/
	void read_sessions();
	/**
	    @return An std::string with the id of the specific session that contains a given problem id. Blank string if no matches.
	*/
	string find_in_sessions(string prob) const;
	/**
	    @return True if a given Session id exists in the @ref Session list, false otherwise.
	*/
	bool exists_session(string target) const;
	/**
	    Inserts session onto the list of sessions.
	    @param id The id for the new session.
	    @param new_session The already initialized @ref Session instance to be added.
	*/
	void insert_session(Session new_session);
	void insert_session(string session_id);
	/**
	    @return Integer with the amount of @ref Session contained in the list.
	*/
	int size();
	/**
	    @param id Valid identifier of an exiting Session instance.
	    @return Session isntane reference
	*/
	stringstream get_problems_in_session(string session_id);
	Session& get_session(string id) const;
	void list_sessions() const;
	void list_sessions(const string& session_id) const;
	~Sessions();
};
#endif
