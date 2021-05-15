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
    /** @brief Set of problems retrieved from every Session in the Course.*/
    set<string> problem_set;
    /** @brief Integer that is increased after every problem session_insertion. Allows an easy way to check whether the Course follows the no intersection rule between problems from sessions. */
    int expected_size = 0;
    /** @brief List of sessions, contained in an std::set in a lexicographically sorted fashion*/
    set<string> session_list_ordered;

    /** @brief List of sessions, contained in an std::vector in the same order they were inserted on Course initialization*/
    vector<string> session_list;
    /** @brief Number of active users coursing the given Course.*/
    int are_coursing = 0;
    /** @brief Number of total active and past users that have completed the Course.*/
    int have_coursed = 0;
    /**
	@param session_id Id of session.
	@pre Always true.
	@post The given @p session_id has been inserted in the list of session ids.
    */
    void session_insertion(const string& session_id);
    public:
	Course();
	/**
	  @brief Course size getter.
	  @pre Always true.
	  @return Integer with the amount of sessions that form the implicit parameter.
	*/
	int size() const;
	/**
	  @brief Getter of the size of the Course's problem list.
	    @pre Always true.
	    @return Integer with the amount of problems contained in the Course instance(total number of problems from every contained session).
	*/
	int amount_problems() const;
	/**
	    @brief Validity checker of a Course instance.
	    @return True if there is no repeated problem across the different sessions stored in the implicit parameter. False otherwise.
	*/
	bool is_legal();
	/**
	    @brief Session belonging to the Course checker.
	    @param session_id Id of the Session instance to search for.
	    @pre Always true.
	    @return Boolean True if a Session with @p session_id as its identifier exists. False otherwise.
	*/
	bool session_exists(const string& session_id) const;
	//reads n sessions, each with their specific id
	/**
	  @brief Course's session list initializer from standard input.
	  @param session_list List of Session instances.
	  @pre Always true.
	  @post Session ids are read from standard input, and the problems contained in the sessions by the  given ids are pushed into the implicit parameter.
	*/
	void read_course(const Sessions& session_list);
	/**
	  @brief Printer of the ids of sessions that form the Course.
	  @pre Always true
	  @post Ids of sessions that form the implicit parameter are printed in stantard output.
	*/
	void info_course() const;
	/**
	  @brief Getter of active coursing users.
	  @pre Always true.
	  @return Integer with the amount of active users currently coursing the course.
	*/
	int users_coursing() const;
	/**
	  @brief Getter of total completions of the course.
	  @pre Always true.
	  @return Integer with the amount of users that have completed the course at some point.
	*/
	int have_completed() const;
	/**
	  @brief Increaser of counter of active Users coursing the given Course.
	  @pre Always true.
	  @return Increases by one unit the counter of active users coursing the Course.
	*/
	void increase_coursing();
	/**
	  @brief Increaser of counter of total completions of the given Course.
	  @pre Always true.
	  @return Increases by one unit the counter of users that have completed the Course.
	*/
	void increase_completed();
	/**
	  @brief Decreaser of counter of active Users coursing the given Course.
	  @pre Always true.
	  @return Decreases by one unit the counter of active users coursing the Course.
	*/
	void decrease_coursing();
	/**
	  @brief Index-based (vector-like) Session id getter.
	  @param i Integer that performs as an index
	  @pre @p i is lesser that the implicit parameter size.
	  @return Id of the session in the given (sorted) position set by the @p i index.
	*/
	string get_session_id(int i) const;
	/**
	  @brief Index-based (vector-like) Problem id getter.
	  @param i Integer that performs as an index
	  @pre @p i is lesser that the implicit parameter problem list size.
	  @return Id of the problem in the given (sorted) position set by the @p i index.
	*/
	string get_problem_id(int i) const;
	/**
	  @brief Insertion of Problem ids into the Course.
	  @param problem_id Id of a problem.
	  @pre Always true.
	  @post The id of a given problem @p problem_id has been individually pushed into the Course problem list.
	*/
	void insert_problem(const string& problem_id);
	/**
	  @brief Checker of existence of a problem within the Course.
	  @param problem_id Id of a problem.
	  @pre Always true.
	  @return True if an id with the given @p problem_id exists in the Course problem list.
	*/
	bool find_problem(const string& problem_id) const;
	//we assume the problem exists
	/**
	  @brief Finder of the id of the Session that contains the given problem.
	  @param problem_id Id of a problem
	  @param session_list List of Session instances to search for the problem in.
	  @pre Problem with the given @p problem_id exists inside the Course's problem list.
	  @post An std::string that contains the id of the Session instance where the problem_id has been found to be in.
	*/
	string session_of_problem(const string& problem_id, const Sessions& session_list);
	/**
	  @brief User solvable problems initializer (used on sign in).
	  @param session_list List of Session instances.
	  @param user_id Id of a User instance which is to be referred
	  @param user_list List of User instances
	  @pre User with the given @p user_id exists in the @p user_list.
	  @post For each session contained inside the implicit parameter, problems from inside it are pushed into the solvable problems list of the User by the id of @p user_id.
	*/
	void init_solvable_from_sessions(Sessions& session_list, const string& user_id, Users& user_list);

	~Course();
};



#endif
