#include "evaluator.hh"

using namespace std;

void Evaluator::init()
{
    problem_list.read_problems();
    session_list.read_sessions();
    course_list.read_courses();
}

void Evaluator::console()
{
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
	    this->add_problem(problem);
	}
	else if (command == "nueva_sesion" or command == "ns")
	{
	    string session;
	    cin >> session;
	    this->add_session(session);
	}
	else if (command == "nuevo_curso" or command == "nc")
	{
	    int course;
	    cin >> course;
	    this->add_course(course);
	}
	else if (command == "alta_usuario" or command == "a")
	{
	    string user;
	    cin >> user;
	    this->add_user(user);
	}
	else if (command == "baja_usuario" or command == "b")
	{
	    string user;
	    cin >> user;
	    this->remove_user(user);
	}
	else if (command == "inscribir_curso" or command == "i")
	{
	    string user;
	    cin >> user;

	    int course;
	    cin >> course;
	    
	    this->add_to_course(user, course);
	}
	else if (command == "curso_usuario" or command == "cu")
	{
	    string user;
	    cin >> user;
	    this->tell_usr_course(user);
	}
	else if (command == "sesion_problema" or command == "sp")
	{
	    int course;
	    cin >> course;
	    string user;
	    cin >> user;
	    this->find_problem_session(course, user);
	}
	else if (command == "problemas_resueltos" or command == "pr")
	{
	    string user;
	    cin >> user;
	    this->tell_solved_probs(user);
	}
	else if(command == "problemas_enviables" or command == "pe")
	{
	    string user;
	    cin >> user;
	    this->tell_solvable_probs(user);
	}
	else if (command == "envio" or command == "e")
	{
	    string user;
	    cin >> user;
	    string problem;
	    cin >> problem;
	    bool successful;
	    cin >> successful;
	    this->deliver_problem(user, problem, successful);
	}
	else if (command == "listar_problemas" or command == "lp")
	{
	    this->tell_prob_list();
	}
	else if (command == "escribir_problema" or command == "ep")
	{
	    string problem;
	    cin >> problem;
	    this->tell_prob_list(problem);
	}
	else if (command == "listar_sesiones" or command == "ls")
	{
	    this->tell_session();
	}
	else if (command == "escribir_sesion" or command == "es")
	{
	    string session;
	    cin >> session;
	    this->tell_session(session);
	}
	else if (command == "listar_cursos" or command == "lc")
	{
	    this->tell_courses();
	}
	else if (command == "escribir_curso" or command == "ec")
	{
	    int course;
	    cin >> course;
	    this->tell_courses(course);
	}
	else if (command == "listar_usuarios" or command == "lu")
	{
	    this->tell_users();
	}
	else if (command == "escribir_usuario" or command == "eu")
	{
	    string user;
	    cin >> user;
	    this->tell_users(user);
	}
	
	// no need to call destructor of args queue, since we assume
	// it is empty after every function return

	cin >> command;
    }
}
