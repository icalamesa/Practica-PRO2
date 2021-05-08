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
    set<string> problem_set;
    int expected_size = 0;
    set<string> session_list_ordered;
    vector<string> session_list;
    int are_coursing = 0;
    int have_coursed = 0;
    void insertion(const string& ses);
    public:
	Course();
	int size() const;
	int amount_problems() const;
	/**
	    @return True if there is no repeated problem across the different sessions stored in the implicit parameter. False otherwise.
	*/
	bool is_legal();
	//[>*
	    //@param target_problem The problem id to be searched.
            //@pre @p target_problem is an string correctly formatted. A problem with @p target_problem as an identifier exists.
	    //@return An std::string with the id of the internal session that contains the given problem id. If it does not exist, the string returned is empty.
	//*/
	////NEED REVISION
	//string find_session_of_problem(const string& target_problem, Sessions& session_list) const;
	/**
	    @param session_id Id of the Session instance to search for.
	    @pre No precondition.
	    @return Boolean True if a Session with @p session_id as its identifier exists. False otherwise.
	*/
	bool session_exists(const string& session_id) const;
	//reads n sessions, each with their specific id
	void read_course(const Sessions& session_list);
	void info_course() const;

	int users_coursing() const;
	int have_completed() const;
	void increase_coursing();
	void increase_completed();
	void decrease_coursing();
	string get_session_id(int i) const;
	string get_problem_id(int i) const;
	void insert_problem(const string& problem_id);
	bool find_problem(const string& problem_id) const;
	//we assume the problem exists
	string session_of_problem(const string& problem_id, const Sessions& session_list);
	void init_solvable_from_sessions(Sessions& session_list, const string& user_id, Users& user_list);

	~Course();
};



#endif
