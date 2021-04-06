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
    queue<string> args;
    while(command != static_cast<string>("fin"))
    {
	if (command == "nuevo_problema" or command == "np")
	{
	    //reads p string
	    cin >> command;
	    args.push(command);
	    //calls function with the given strings
	    this->add_problem(args);
	}
	else if (command == "nueva_sesion" or command == "ns")
	{
	    cin >> command;
	    args.push(command);
	    this->add_session(args);
	}
	else if (command == "nuevo_curso" or command == "nc")
	{
	    cin >> command;
	    args.push(command);
	    this->add_course(args);
	}
	else if (command == "alta_usuario" or command == "a")
	{
	    cin >> command;
	    args.push(command);
	    this->add_user(args);
	}
	else if (command == "baja_usuario" or command == "b")
	{
	    cin >> command;
	    args.push(command);
	    this->remove_user(args);
	}
	else if (command == "inscribir_curso" or command == "i")
	{
	    cin >> command;
	    args.push(command);
	    cin >> command;
	    args.push(command);
	    this->add_to_course(args);
	}
	else if (command == "curso_usuario" or command == "cu")
	{
	    cin >> command;
	    args.push(command);
	    this->tell_usr_course(args);
	}
	else if (command == "sesion_problema" or command == "sp")
	{
	    cin >> command;
	    args.push(command);
	    cin >> command;
	    args.push(command);
	    this->find_problem_session(args);
	}
	else if (command == "problemas_resueltos" or command == "pr")
	{
	    cin >> command;
	    args.push(command);
	    this->tell_solved_probs(args);
	}
	else if (command == "envio" or command == "e")
	{
	    cin >> command;
	    args.push(command);
	    cin >> command;
	    args.push(command);
	    cin >> command;
	    args.push(command);
	    this->deliver_problem(args);
	}
	else if (command == "listar_problemas" or command == "lp")
	{
	    this->tell_prob_list();
	}
	else if (command == "escribir_problema" or command == "ep")
	{
	    cin >> command;
	    args.push(command);
	    this->tell_prob_list(args);
	}
	else if (command == "listar_sesiones" or command == "ls")
	{
	    this->tell_session();
	}
	else if (command == "escribir_sesion" or command == "es")
	{
	    cin >> command;
	    args.push(command);
	    this->tell_session(args);
	}
	else if (command == "listar_cursos" or command == "lc")
	{
	    this->tell_courses();
	}
	else if (command == "escribir_curso" or command == "ec")
	{
	    cin >> command;
	    args.push(command);
	    this->tell_courses(args);
	}
	else if (command == "listar_usuarios" or command == "lu")
	{
	    this->tell_users();
	}
	else if (command == "escribir_usuario" or command == "eu")
	{
	    cin >> command;
	    args.push(command);
	    this->tell_users(args);
	}
	
	// no need to call destructor of args queue, since we assume
	// it is empty after every function return

	cin >> command;
    }
}
