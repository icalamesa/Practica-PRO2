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
#include <vector>
#include <string>
/** @endcond */


#ifndef SESSION_HH
#define SESSION_HH

/** @brief Class that behaves as a problem set with completion requisites.

    Class that represents a session, composed of multiple problems. A system of prerequisites is implemented so that problems may require other problems to be resolved first.
*/
class Session
{
    BinTree<string> problem_node;
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
    public:
	Session();
	Session(string session_id);
	/**
	    Reads problems from standard input to initialize the implicit parameter.
	    @pre The implicit parameter is empty (no problems in it). It has not been initialized before. The standard input read problems do not repeat. Standard input follows the format requirements(read in preorder).
	    @post Problems read are inserted into the Session. 
	*/
	void read_session();
	
	/**
	    @p target_problem size is greater than zero
	    @return True if the target problem id is found in this session problem list. False otherwise.
	*/
	bool find(string target_problem) const;
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
	int size() const;
	bool operator< (const Session& other) const;
	bool operator== (const Session& other) const;


	void insert_problem(const string& problem_id);
	~Session();
};


#endif
