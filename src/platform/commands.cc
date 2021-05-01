#include "users.hh"
#include "sessions.hh"
#include "courses.hh"
#include "sessions.hh"
#include "problems.hh"
#include "users.hh"
#include <iostream>
using namespace std;


void add_problem(Problem_repo& problem_list)
{
    string problem_id;
    cin >> problem_id;
    problem_list.insert_problem(problem_id);
}

void add_session(Sessions& session_list)
{
    string id;
    cin >> id;
    Session new_session(id);
    new_session.read_session();
    session_list.insert_session(new_session);
}

//important: does NOT read course id. It reads number of sessions to be read
void add_course(Courses& course_list, Sessions& session_list)
{
    Course new_course;
    new_course.read_course();

    vector<string> probs;
    cout << "VECTOR " << endl;
    int course_size = new_course.size();
    cout << "HOLA " << endl;
    cout << "COURSE SIZE: "<<course_size << endl;
    for (int i = 0; i < course_size; i++)
    {
	string target_session = new_course.get_session_id(i);
	cout << "PAST COURSE " << endl;
	//int session_size = session_list.session_size(target_session);
	cout << "FIRST FOR: " << target_session << ' ' << "session_size" << endl;
	Session& ses = session_list.get_session(target_session);
	int session_size = ses.size();
	for (int j = 0; j < session_size; j++)
	{
	    string problem = ses.get_i_problem(j);
	    cout << problem << "\t";
	    probs.push_back(problem);
	    /*cout << "Entro al for" << ' ' << endl;
	    cout << "puta" << ' ';
	    probs.push_back(session_list.get_i_problem_id(target_session, j));
	    cout << "puta" << ' ';*/
	}
	cout << endl;
    }
    for ( const auto& str : probs )
    {
	cout << str << ' ';
	new_course.insert_problem(str);
    }
    cout << endl;
    if (new_course.is_legal())
    {
	course_list.insert_course(new_course);
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

void sign_in_course(string user_id, int course_id, Users& user_list, Courses& course_list, Sessions& session_list)
{
    bool u_exist = false, c_exist = false;
    u_exist = user_list.user_exists(user_id);
    //need to add the method under this line
    cout << "PREIF " << endl;
    c_exist = course_list.course_exists(course_id);
    if (u_exist and c_exist)
    {
	if (not user_list.is_coursing(user_id))
	{
	    user_list.sign_in_course(user_id, course_id);

	    course_list.increase_coursing(course_id);
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
	if (not c_exist) cout << "error: el curso no existe" << endl;
    }
}

void tell_usr_course(string user_id, Users& user_list)
{
    if (user_list.user_exists(user_id))
    {
	user_list.tell_course(user_id);
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
    p_exist = problem_list.problem_exists(problem_id);
    if (c_exist and p_exist)
    {
	string session; //= course_list.find_session_id(course_id, problem_id);
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
	user_list.list_solvable_problems(user_id);
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

static string fetch_problem(Users& user_list, Sessions& session_list)
{

}
