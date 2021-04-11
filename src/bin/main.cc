/** @file
    @brief The platform's main file.

    The main file is a C++ program's core file. As such, it is listed here.
    In here we can find how the core of the platform works without having to dive deep into the implementation.

    @author Ivan Cala Mesa
    @date 1st of April of 2021
*/

#include "courses.hh"
#include "commands.hh"
/** @cond */
#include <iostream>
/** @endcond */

using namespace std;

int main()
{
    Problem_repo problem_list;
    problem_list.read_problems();

    Sessions session_list;
    session_list.read_sessions();

    Courses course_list;
    course_list.read_courses();

    Users user_list;
    user_list.read_users();
    
    string command;
    cin >> command;
    while(command != static_cast<string>("fin"))
    {
	if (command == "nuevo_problema" or command == "np")
	{
	    string problem;
	    //reads p string
	    cin >> problem;
	    //calls function with the given strings
	    add_problem(problem, problem_list);
	}
	else if (command == "nueva_sesion" or command == "ns")
	{
	    string session;
	    cin >> session;
	    add_session(session, session_list);
	}
	else if (command == "nuevo_curso" or command == "nc")
	{
	    int course;
	    cin >> course;
	    add_course(course, course_list);
	}
	else if (command == "alta_usuario" or command == "a")
	{
	    string user;
	    cin >> user;
	    add_user(user, user_list);
	}
	else if (command == "baja_usuario" or command == "b")
	{
	    string user;
	    cin >> user;
	    remove_user(user, user_list);
	}
	else if (command == "inscribir_curso" or command == "i")
	{
	    string user;
	    cin >> user;

	    int course;
	    cin >> course;
	    
	    add_to_course(user, course, user_list);
	}
	else if (command == "curso_usuario" or command == "cu")
	{
	    string user;
	    cin >> user;
	    tell_usr_course(user, user_list);
	}
	else if (command == "sesion_problema" or command == "sp")
	{
	    int course;
	    cin >> course;
	    string user;
	    cin >> user;
	    find_problem_session(course, user, course_list, problem_list);
	}
	else if (command == "problemas_resueltos" or command == "pr")
	{
	    string user;
	    cin >> user;
	    tell_solved_probs(user, user_list);
	}
	else if(command == "problemas_enviables" or command == "pe")
	{
	    string user;
	    cin >> user;
	    tell_solvable_probs(user, user_list, course_list);
	}
	else if (command == "envio" or command == "e")
	{
	    string user;
	    cin >> user;
	    string problem;
	    cin >> problem;
	    bool successful;
	    cin >> successful;
	    deliver_problem(user, problem, successful, user_list, problem_list);
	}
	else if (command == "listar_problemas" or command == "lp")
	{
	    tell_prob_list(problem_list);
	}
	else if (command == "escribir_problema" or command == "ep")
	{
	    string problem;
	    cin >> problem;
	    tell_prob_list(problem, problem_list);
	}
	else if (command == "listar_sesiones" or command == "ls")
	{
	    tell_session(session_list);
	}
	else if (command == "escribir_sesion" or command == "es")
	{
	    string session;
	    cin >> session;
	    tell_session(session, session_list);
	}
	else if (command == "listar_cursos" or command == "lc")
	{
	    tell_courses(course_list);
	}
	else if (command == "escribir_curso" or command == "ec")
	{
	    int course;
	    cin >> course;
	    tell_courses(course, course_list);
	}
	else if (command == "listar_usuarios" or command == "lu")
	{
	    tell_users(user_list);
	}
	else if (command == "escribir_usuario" or command == "eu")
	{
	    string user;
	    cin >> user;
	    tell_users(user, user_list);
	}
	
	// no need to call destructor of args queue, since we assume
	// it is empty after every function return

	cin >> command;
    }
}

