
/**
    @file
    @brief Evaluator main program class.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/

#include "users.hh"
#include "courses.hh"
/**
    @brief Class that contains a deployable instance of the Evaluator Platform.

    The Evaluator class behaves single-handedly as the Evaluator platform itself. It contains multiple interfaces such as @ref Courses, @ref Problem_repo and @ref Users. Evaluator itself can be deployed elsewhere, and only one evaluator instance can be on use in a single processor thread.
*/
class Evaluator
{
    Users users_list;

    Problem_repo problem_list;

    Sessions session_list;

    Courses course_list;

    public:
    //1.
    void add_problem(string problem_id);

    //2.
    void add_session(string session_id);

    //3.
    void add_course(int course_id);

    //4.
    void add_user(string user_id);

    //5.
    void remove_user(string user_id);

    //6.
    void add_to_course(string user_id, int course_id);

    //7.
    void tell_usr_course(string user_id);

    //8.
    void find_problem_session(int course_id, string user_id);

    //9.
    void tell_solved_probs(string user_id);

    //10.
    void tell_solvable_probs(string user_id);

    //11.
    void deliver_problem(string user_id, string problem_id, bool successful);

    //12.
    void tell_prob_list();
    void tell_prob_list(string problem_id);

    //13.
    void tell_session();
    void tell_session(string user_id);

    //14.
    void tell_courses();
    void tell_courses(int course_id);

    //15.
    void tell_users();
    void tell_users(string user_id);
    /**
        Initializes the multiple internal objects contained in the implicit parameter. These instantiations require reading from standard input.
        @pre Standard input text follows the input format for @ref Problem_repo, @ref Courses, and @ref Users.
        @post Internal container interfaces have been initialized.
    */
	void init();
    /**
        Starts a command-line mode. Executs commands depending on the input command. Abbrevations for every commad have been defined.
    */
	void console();
};
