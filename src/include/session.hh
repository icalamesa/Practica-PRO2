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
    BinTree<string> problem_node;
    map<string, std::pair<string, string>> tree_map;
    int _size = 0;
    void recalc_size();
    string id;
    /**
	@return A std::set<std::string> containing the id of the problems contained in the implicit parameter.
    */
    set<string> list_of_problems;
    void fill_problem_set(BinTree<string>& tree);
    bool search_problem(const BinTree<string>& tree, string& target_problem) const;
    void print_session(const BinTree<string>&tree) const;
    void initial_problem_fetching(User& usr, const BinTree<string>& tree);
    public:
	Session();
	Session(const string& session_id);
	/**
	    Reads problems from standard input to initialize the implicit parameter.
	    @pre The implicit parameter is empty (no problems in it). It has not been initialized before. The standard input read problems do not repeat. Standard input follows the format requirements(read in preorder).
	    @post Problems read are inserted into the Session. 
	*/
	void read_session();
	void read_session_problems();
	
	/**
	    @p target_problem size is greater than zero
	    @return True if the target problem id is found in this session problem list. False otherwise.
	*/
	bool find(const string& target_problem) const;
	/**
	    @param target_problem std::string containing the identifier of a problem
	    @p target_problem size is greater than zero
	    @return A std::string with the id of the implicit parameter.
	*/
	string get_session_with_problem_id(string target_problem);
        /**
            @param session_id Id of the specific session.
            @pre No precondition.
            @post Info on the session is displayed on Standard output.
        */
        void info_session() const;
	string get_id() const;
	string get_i_problem(int i) const;
	string get_first_problem_id() const;
	pair<string, string> get_next_problems(const string& problem_id) const;
	int size() const;
	bool operator< (const Session& other) const;
	bool operator== (const Session& other) const;

	
	void init_solvable_problems_from_user(const string& user_id, Users& user_list);
	void problem_fetching(User& usr, const string& problem_id);
	void insert_problem(const string& problem_id);
	~Session();
};


#endif
