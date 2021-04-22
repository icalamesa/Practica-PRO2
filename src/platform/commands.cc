#include "evaluator.hh"

using namespace std;

void init(Problem_repo& problem_list, Sessions& session_list, Courses& course_list)
{
    problem_list.read_problems();
    session_list.read_sessions();
    course_list.read_courses();
}

void console(Problem_repo& problem_list, Sessions& session_list, Courses& course_list)
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

void add_problem(string problem_id, Problem_repo& problem_list)
{
    problem_list.insert_problem(problem_id);
}

void add_session(string session_id, Sessions& session_list)
{
    Session new_session;
    new_session.read_session();
    session_list.insert_session(session_id, new_session);
}

//important: does NOT read course id. It reads number of sessions to be read
void add_course(int n, Courses& course_list)
{
    Course new_course;
    new_course.read_course(int n);
    if (new_course.is_legal())
    {
	course_list.insert_course(course_list);
    }
    else
    {
	//error msg course not legal
    }
}

void add_user(string user_id, Users& user_list)
{
    //error message if required is printed from within the function
    if (not user_list.user_exists(user_id))
    {
	user_list.insert_user(user_id);
    }
    else 
    {
	cout << "error: el usuario ya existe" << endl;
    }
}

void remove_user(string user_id, Users& user_list)
{
    if (user_list.user_exists(user_id))
    {
	user_list.remove_user(user_id);
    }
    else
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void add_to_course(string user_id, int course_id, Users& user_list, Courses& course_list)
{
    bool u_exist = false, c_exist = false;
    u_exist = user_list.user_exists(user_id);
    //need to add the method under this line
    c_exist = course_list.course_exists(course_id);
    if (u_exist and c_exist)
    {
	user_list.sign_in_course(user_id, course_id);
    }
    else
    {
	if (not u_exist) cout << "error: el usuario no existe" << endl;
	if (not c_exist) cout << "error: el curso no existe" << endl;
    }
}

void tell_usr_course(string user_id, Users& user_list)
{
    if (user_list.user_exists(user_id))
    {
	user_list.get_user(user_id).tell_course();
    }
    else 
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void find_problem_session(int course_id, string problem_id, Courses& course_list, Problem_repo& problem_list)
{
    bool c_exist = false, p_exist = false;
    c_exist = course_list.course_exists(course_id);
    p_exist = problem_exist(problem_id);
    if (c_exist and p_exist)
    {
	string session = course_list.find_session_id(course_id, problem_id);
	if (session.empty())
	{
	    cout << "error: el problema no pertenece al curso" << endl;
	}
	else
	{
	    cout << session << endl;
	}
    }
    else
    {
	if (not c_exist) cout << "error: el curso no existe" << endl;
	if (not p_exist) cout << "error: el problema no existe" << endl;
    }
}

void tell_solved_probs(string user_id, Users& user_list)
{
    if (user_list.user_exists(user_id))
    {
	user_list.list_solved_problems_by(user_id);
    }
    else
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void tell_solvable_probs(string user_id, Users& user_list, Courses& course_list)
{
    if (user_list.user_exists(user_id))
    {
	user_list.list_solvable_problems(user_id, course_list);
    }
    else
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void deliver_problem(string user_id, string problem_id, bool successful, Users& user_list, Problem_repo& problem_list)
{
    //no info yet
}

void tell_prob_list(Problem_repo& problem_list)
{
    //need to add the method under this line
    problem_list.list_problems();
}

void tell_prob_list(string problem_id, Problem_repo& problem_list)
{
    if (problem_list.problem_exists(problem_id))
    {
	cout << problem_id << ' ';
        problem_list.get_problem(problem_id).info_problem();
        cout << endl; //doshit
    }
    else
    {
        cout << "error: el problema no existe" << endl;
    }
}

void tell_session(const Session& session_list)
{
    //need to add this method
    session_list.list_sessions();
}

void tell_session(string session_id, const Session& session_list)
{
    if (session_list.exists_session(session_id))
    {
	session_list.get_session(session_id).info_session();
    }
    else
    {
        cout << "error: la sesion no existe" << endl;
    }
}

void tell_courses(Courses& course_list)
{
    course_list.list_courses();
}

void tell_courses(int course_id, Courses& course_list)
{
    if (course_list.course_exists(course_id))
    {
	course_list.get_course().info_course(); //do shit here
    }
    else
    {
	cout << "error: el curso no existe" << endl;
    }
}
void tell_users(Users& user_list)
{
    user_list.list_users();
}
void tell_users(string user_id, Users& user_list)
{
    if (user_list.user_exists(user_id))
    {
	user_list.get_user(user_id).info_user(); //do shit here;
    }
    else
    {
        cout << "error: el usuario no existe" << endl;
    }
}


