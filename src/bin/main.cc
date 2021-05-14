/** @file
    @brief The platform's main file.

    The main file is a C++ program's core file. As such, it is listed here.
    The Evaluator main program works as follow. The main program will start by reading an initial number of problems P >0 and a sequence of P strings identifying those problems. It will then read an initial number of sessions Q>0 and a sequence of Q sessions. For each session, its name and a sequence of problem identifiers will be entered, following a preordering of its prerequisite structure. Then, an initial number of courses N >0 and a sequence of N courses will be read, identified by the order in which they are read. For each course, between 1 and N, the number of sessions S>0 of the course will be read first and then a sequence of S session identifiers, valid and without repetitions. To finish the initializations, a number M of initially registered users will be read followed by their M identifiers. Note that the magnitudes P, Q, N and M are not constant; P, Q and N may increase when new problems, new sessions or new courses are added later. Neither problems, sessions nor courses will ever be deleted, and once created, neither sessions nor courses can be modified. Therefore, the number of sessions S of a course will be constant, as well as the number of problems of a session. The number M of users will vary (increase or decrease) as new users register or unsubscribe from the platform.

    @author Ivan Cala Mesa
    @date 1st of April of 2021
*/

#include "courses.hh"
#include "sessions.hh"
#include "problems.hh"
#include "users.hh"
#include "commands.hh"
/** @cond */
#include <iostream>
/** @endcond */

using namespace std;
/** @brief Main program of the Evaluator Platform
  
*/
int main()
{
    Problem_repo problem_list;
    problem_list.read_problems();

    Sessions session_list;
    session_list.read_sessions();

    Courses course_list;
    course_list.read_courses(session_list);

    Users user_list;
    user_list.read_users();
    
    string command;
    cin >> command;
    while(command != static_cast<string>("fin"))
    {
	if (command == "nuevo_problema" or command == "np")
	{
	    string problem_id;
	    cin >> problem_id;
	    cout << '#' << command << ' ' << problem_id << endl;
	    add_problem(problem_list, problem_id);
	}
	else if (command == "nueva_sesion" or command == "ns")
	{
	    string session_id;
	    cin >> session_id;
	    cout << '#' << command << ' ' << session_id << endl;
	    add_session(session_list, session_id);
	}
	else if (command == "nuevo_curso" or command == "nc")
	{
	    cout << '#' << command << endl;
	    add_course(course_list, session_list);
	    cout << endl;
	}
	else if (command == "alta_usuario" or command == "a")
	{
	    string user;
	    cin >> user;
	    cout << '#' << command << ' ' << user << endl;
	    add_user(user, user_list);
	}
	else if (command == "baja_usuario" or command == "b")
	{
	    string user;
	    cin >> user;
	    cout << '#' << command << ' ' << user << endl;
	    remove_user(user, user_list, course_list);
	}
	else if (command == "inscribir_curso" or command == "i")
	{
	    string user;
	    cin >> user;

	    int course;
	    cin >> course;
	    
	    cout << '#' << command << ' ' << user << ' ' << course << endl;
	    sign_in_course(user, course, user_list, course_list, session_list);
	}
	else if (command == "curso_usuario" or command == "cu")
	{
	    string user;
	    cin >> user;
	    cout << '#' << command << ' ' << user << endl;
	    tell_usr_course(user, user_list);
	}
	else if (command == "sesion_problema" or command == "sp")
	{
	    int course;
	    cin >> course;
	    string problem;
	    cin >> problem;
	    cout << '#' << command << ' ' << course << ' ' << problem << endl;
	    find_problem_session(course, problem, course_list, problem_list, session_list);
	}
	else if (command == "problemas_resueltos" or command == "pr")
	{
	    string user;
	    cin >> user;
	    cout << '#' << command << ' ' << user << endl;
	    tell_solved_probs(user, user_list);
	}
	else if(command == "problemas_enviables" or command == "pe")
	{
	    string user;
	    cin >> user;
	    cout << '#' << command << ' ' << user << endl;
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
	    cout << '#' << command << ' ' << user << ' ' << problem << ' ' << successful << endl;
	    deliver_problem(user, problem, successful, user_list, problem_list, session_list, course_list);
	}
	else if (command == "listar_problemas" or command == "lp")
	{
	    cout << '#' << command << endl;
	    tell_prob_list(problem_list);
	}
	else if (command == "escribir_problema" or command == "ep")
	{
	    string problem;
	    cin >> problem;
	    cout << '#' << command << ' ' << problem << endl;
	    tell_prob_list(problem, problem_list);
	}
	else if (command == "listar_sesiones" or command == "ls")
	{
	    cout << '#' << command << endl;
	    tell_session(session_list);
	}
	else if (command == "escribir_sesion" or command == "es")
	{
	    string session;
	    cin >> session;
	    cout << '#' << command << ' ' << session << endl;
	    tell_session(session, session_list);
	}
	else if (command == "listar_cursos" or command == "lc")
	{
	    cout << '#' << command << endl;
	    tell_courses(course_list);
	}
	else if (command == "escribir_curso" or command == "ec")
	{
	    int course;
	    cin >> course;
	    cout << '#' << command << ' ' << course << endl;
	    tell_courses(course, course_list);
	}
	else if (command == "listar_usuarios" or command == "lu")
	{
	    cout << '#' << command << endl;
	    tell_users(user_list);
	}
	else if (command == "escribir_usuario" or command == "eu")
	{
	    string user;
	    cin >> user;
	    cout << '#' << command << ' ' << user << endl;
	    tell_users(user, user_list);
	}
	
	cin >> command;
    }
}

