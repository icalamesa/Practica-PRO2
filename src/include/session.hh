/**
    @file
    @brief Session class specification.

    @author Ivan Cala Mesa
    @date 15th of May of 2021
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
    /** @brief BinTree root of the whole problem prerequisites tree. We require this BinTree because it allows an efficient way to print the tree in postorder, without having to perform a superlinear O(n*log(n)) cost algorithm in the std::map.
    */
    BinTree<string> problem_node;
    /** @brief std::map that allows quick search of the children nodes for every problem in the prerequisites tree. Stores '0' if no child node.*/
    map<string, std::pair<string, string>> tree_map;
    std::vector<string> problems;
    /** @brief Identifier of the Session. */
    string id;
    /** 
      @brief Immersion function to read binary trees. 
      @param tree Binary Tree node.

      Reads strings in preorder from Standard input. If such string is not equal to "0", then the function calls itself again 2 times on both of its child nodes, and inserts the root and both children in the map of strings that allows a quick search of what are the children for each node. Otherwise, it does not call itself recursively again. 
      @pre Always true.
      @post A binary tree of strings has been structured, in preorder.
    */
    void fill_problem_set(BinTree<string>& tree);
    /** 
      @brief Recursive printer in postorder of the sessions in the prerequisites tree.
      @param tree BinTree node in the tree.
      @pre @p tree is a non-empty binary tree node.
      @post The whole tree has been printed in standard output in post order.
    */
    void print_session(const BinTree<string>& tree) const;
    /** 
      @brief Immersion function to check and push solvable problems to a User.
      
      If a problem has been solved by a User, recursively calls itself until it finds an empty node, or a problem not solved by the @p usr, in which case the node value gets pushed into the solvable problems list the @p usr holds inside.
      @param usr User instance.
      @param tree Node to be checked
      @pre @p tree is not an empty node.
      @post The solvable problems list has been updated accordingly to the situation of the @p usr (what problems where solved up to that point by it).

    */
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
	    @brief Problem finder within the Session.
	    @param target_problem size is greater than zero
	    @return True if the target problem id is found in this session problem list. False otherwise.
	*/
	bool find(const string& target_problem) const;
        /**
	    @brief Printer method of information of the Session.
            @pre Always true.
            @post Info on the session is displayed on Standard output in the following format:
	    id session_size sessions_in_postorder.
        */
        void info_session() const;
	/**
	  @brief Getter of identifiers.
	  @pre Always true.
	  @return std::string with the id of the implicit parameter.
	*/
	string get_id() const;
	/**
	  @brief Index-based (vector-like) problem_id getter.
	  @param i Integer that performs as an index
	  @pre @p i is lesser than the implicit parameter size.
	  @return Id of the problem in the given (sorted) position set by the @p i index.
	*/
	string get_i_problem(int i) const;
	/**
	  @brief Container size getter.
	  @pre Always true.
	  @return Integer with the amount of problems contained in the implicit parameter.
	*/
	int size() const;
	/**
	  @brief Solvable problems initializer (used on signing in Course).
	  @param user_id Id of a User instance.
	  @param user_list List of User instances.
	  @pre User with the given @p user_id exists withing the @p user_list
	  @post Problems contained inside the implicit parameter have been pushed inside the solvable problems list of the User instance by the id of @p user_id, if not solved before.
	*/
	void init_solvable_problems_from_user(const string& user_id, User_repo& user_list);
	/**
	  @brief Recursive method to insert solvable problems to specific User on submission.
	  @pre Always true.
	  @post Recursively adds problems from the prerequisites tree into the User solvable problems list with @p problem_id as its root.
	*/
	void problem_fetching(User& usr, const string& problem_id);
	/** @brief Comparison of Session std::string identifiers with < operator. */
	bool operator< (const Session& other) const;
	/** @brief Comparison of Session std::string identifiers with == operator. */
	bool operator== (const Session& other) const;
	~Session();
};


#endif
