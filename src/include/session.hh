/**
    @file
    @brief Session class specification.

    @author Ivan Cala Mesa
    @date 1st of April of 2021
*/
using namespace std;
/** @cond */
#include "BinTree.hh"
#include <set>
#include <map>
#include <vector>
#include <string>
/** @endcond */
#include "users.hh"


#ifndef SESSION_HH
#define SESSION_HH

/** @brief Class that behaves as a problem set with completion requisites.

    Class that represents a session, composed of multiple problems. A system of prerequisites is implemented so that problems may require other problems to be resolved first.
*/
class Session
{
    /** @brief BinTree root of the whole problem prerequisites tree.*/
    BinTree<string> problem_node;
    /** @brief std::map that allows quick search of the children of every problem in the prerequisites tree.*/
    map<string, std::pair<string, string>> tree_map;
    /** @brief Identifier of the Session. */
    string id;
    /**	@brief A std::set<std::string> that contains the id of the problems contained in the implicit parameter.*/
    set<string> list_of_problems;
    void fill_problem_set(BinTree<string>& tree);
    bool search_problem_in_tree(const BinTree<string>& tree, string& target_problem) const;
    void print_session(const BinTree<string>&tree) const;
    void immersion_init_solvable_problems_from_user(User& usr, const BinTree<string>& tree);
    public:
	/**
	    @brief Declares uninitialized and unidentified Session.
	*/
	Session();
	/**
	  @param session_id Identifier for the newly constructed Session.
	  @brief Declares Session with its identifier initialized as @p session_id. 
	*/
	Session(const string& session_id);
	/**
	    @brief Reads id and problems from standard input to initialize the implicit parameter.
	    @pre The implicit parameter is empty (no problems in it). It has not been initialized before. The standard input read problems do not repeat. Standard input follows the format requirements(read in preorder).
	    @post Session Identifier and problems read are inserted into the Session. 
	*/
	void read_session();
	/**
	    @brief Reads problems from standard input to initialize the implicit parameter.
	    @pre The implicit parameter is empty (no problems in it). It has not been initialized before. The standard input read problems do not repeat. Standard input follows the format requirements(read in preorder).
	    @post Session problems are read and inserted into the Session. 
	*/
	void read_session_problems();
	
	/**
	    @p target_problem size is greater than zero
	    @return True if the target problem id is found in this session problem list. False otherwise.
	*/
	bool find(const string& target_problem) const;
        /**
            @param session_id Id of the specific session.
            @pre No precondition.
            @post Info on the session is displayed on Standard output.
        */
        void info_session() const;
	/**
	  @pre Always true.
	  @return std::string with the id of the implicit parameter.
	*/
	string get_id() const;
	/**
	  @brief Index-based (vector-like) problem_id getter.
	  @param i Integer that performs as an index
	  @pre @p i is lesser that the implicit parameter size.
	  @return Id of the problem in the given (sorted) position set by the @p i index.
	*/
	string get_i_problem(int i) const;
	/**
	  @param problem_id Id of a problem contained inside the implicit parameter.
	  @pre @p problem_id exists inside the Session instance.
	  @return std::pair containing 2 strings: Both of them representing the children of the given @p problem_id in the prerequisites tree. The given strings contain "0" if no child in a position, either left, right or both.
	*/
	pair<string, string> get_next_problems(const string& problem_id) const;
	/**
	  @pre Always true.
	  @return Integer with the amount of problems contained in th eimplicit parameter.
	*/
	int size() const;
	/**
	  @brief Solvable problems initializer (used on signing in Course).
	  @param user_id Id of a User instance.
	  @param user_list List of User instances.
	  @pre User with the given @p user_id exists withing the @p user_list
	  @post Problems contained inside the implicit parameter have been pushed inside the solvable problems list of the User instance by the id of @p user_id, if not solved before.
	*/
	void init_solvable_problems_from_user(const string& user_id, Users& user_list);
	/**
	  @brief Recursive method to insert solvable problems on delivery.
	  @pre Always true.
	  @post Recursively adds problems from the prerequisites tree into the User solvable problems list with @p problem_id as its root.
	*/
	void problem_fetching(User& usr, const string& problem_id);

	bool operator< (const Session& other) const;
	bool operator== (const Session& other) const;
	~Session();
};


#endif
