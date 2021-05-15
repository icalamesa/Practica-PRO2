#include "users.hh"
#include "sessions.hh"
#include "courses.hh"
#include "sessions.hh"
#include "problems.hh"
#include "users.hh"
#include <iostream>
using namespace std;


void add_problem(Problem_repo& problem_list, const string& problem_id)
{
    if (problem_list.insert_problem(problem_id))
    {
	cout << problem_list.size() << endl;
    }
    else
    {
	cout << "error: el problema ya existe" << endl;
    }
}

void add_session(Sessions& session_list, const string& session_id)
{
    Session new_session(session_id);
    new_session.read_session_problems();
    if (session_list.insert_session(new_session))
    {
	cout << session_list.size() << endl;
    }
    else
    {
	cout << "error: la sesion ya existe" << endl;
    }
}

//important: does NOT read course id. It reads number of sessions to be read
void add_course(Courses& course_list, Sessions& session_list)
{
    Course new_course;
    new_course.read_course(session_list);

    //cout << endl;
    if (new_course.is_legal())
    {
	course_list.insert_course(new_course);
	cout << course_list.size();
    }
    else
    {
	//error msg course not legal
	cout << "error: curso mal formado";
    }
}

void add_user(string user_id, Users& user_list)
{
    //error message if required is printed from within the function
    if (not user_list.user_exists(user_id))
    {
	user_list.insert_user(user_id);
	cout << user_list.size() << endl;

    }
    else 
    {
	cout << "error: el usuario ya existe" << endl;
    }
}

void remove_user(string user_id, Users& user_list, Courses& course_list)
{
    pair<bool, int> result = user_list.remove_user(user_id);
    if (result.first)
    {
	cout << user_list.size() << endl;
	if (result.second != -1)
	{
	    course_list.get_course(result.second).decrease_coursing();
	}
    }
    else
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void sign_in_course(string user_id, int course_id, Users& user_list, Courses& course_list, Sessions& session_list)
{
    (void) session_list;
    bool u_exist = false, c_exist = false;
    u_exist = user_list.user_exists(user_id);
    //need to add the method under this line
    c_exist = course_list.course_exists(course_id);
    if (u_exist and c_exist)
    {
	User& the_user = user_list.get_user(user_id);
	if (not the_user.u_is_coursing())
	{
	    //user_list.sign_in_course(user_id, course_id);
	    the_user.u_sign_in_course(course_id);
	    //course_list.increase_coursing(course_id);
	    Course& the_course = course_list.get_course(course_id);
	    the_course.increase_coursing();
	    //need to push problems
	    //course_list.get_course(course_id).init_solvable_from_sessions(session_list, user_id, user_list);
	    the_course.init_solvable_from_sessions(session_list, user_id, user_list);
	    cout << course_list.are_coursing(course_id) << endl;
	}
	else
	{
	    cout << "error: usuario inscrito en otro curso" << endl;
	}
    }
    else
    {
	if (not u_exist) cout << "error: el usuario no existe" << endl;
	else if (not c_exist) cout << "error: el curso no existe" << endl;
    }
}

void tell_usr_course(string user_id, Users& user_list)
{
    if (user_list.user_exists(user_id))
    {
	cout << user_list.get_user(user_id).u_tell_course() << endl;
    }
    else 
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void find_problem_session(int course_id, string problem_id, Courses& course_list, Problem_repo& problem_list, Sessions& session_list)
{
    bool c_exist = false, p_exist = false;
    c_exist = course_list.course_exists(course_id);
    p_exist = problem_list.problem_exists(problem_id);
    if (c_exist and p_exist)
    {
	if (course_list.get_course(course_id).find_problem(problem_id))
	{
	    int course_size = course_list.course_size(course_id);
	    string session;
	    for (int i = 0; i < course_size; i++)
	    {
		session = course_list.get_course(course_id).get_session_id(i);
		Session& ses = session_list.get_session(session);
		if (ses.find(problem_id))
		{
		    cout << session << endl;
		}
	    }
	}
	else
	{
	    cout << "error: el problema no pertenece al curso" << endl;
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
	user_list.get_user(user_id).u_list_solved();
    }
    else
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void tell_solvable_probs(string user_id, Users& user_list, Courses& course_list)
{
    (void) course_list;
    if (user_list.user_exists(user_id))
    {
	User& the_user = user_list.get_user(user_id);
	if (the_user.u_is_coursing())
	{
	    the_user.u_list_solvable();
	}
	else
	{
	    cout << "error: usuario no inscrito en ningun curso" << endl;
	}
    }
    else
    {
	cout << "error: el usuario no existe" << endl;
    }
}

void deliver_problem(string user_id, string problem_id, bool successful, Users& user_list, Problem_repo& problem_list, Sessions& session_list, Courses& course_list)
{
    User& usr = user_list.get_user(user_id);
    int course = usr.u_tell_course();
    usr.u_deliver_problem(problem_id, successful);
    problem_list.get_problem(problem_id).problem_delivery(successful);
    if (successful)
    {
	string session_id = course_list.get_course(usr.u_tell_course()).session_of_problem(problem_id, session_list);
	session_list.get_session(session_id).problem_fetching(usr, problem_id);
	if (usr.u_update_course())
	{
	    course_list.get_course(course).decrease_coursing();
	    course_list.get_course(course).increase_completed();
	}
    }
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
        problem_list.get_problem(problem_id).info_problem();
    }
    else
    {
        cout << "error: el problema no existe" << endl;
    }
}

void tell_session(const Sessions& session_list)
{
    //need to add this method
    session_list.list_sessions();
}

void tell_session(const string& session_id, const Sessions& session_list)
{
    if (session_list.exists_session(session_id))
    {
	session_list.list_sessions(session_id);
    }
    else
    {
        cout << "error: la sesion no existe" << endl;
    }
}

void tell_courses(Courses& course_list)
{
    course_list.list_all_courses();
}

void tell_courses(int course_id, Courses& course_list)
{
    if (course_list.course_exists(course_id))
    {
	course_list.list_course(course_id);
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
	user_list.list_users(user_id); //do shit here;
    }
    else
    {
        cout << "error: el usuario no existe" << endl;
    }
}

//AUX FUNCTIONS

