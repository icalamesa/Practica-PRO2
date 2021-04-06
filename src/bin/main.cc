#include "courses.hh"
#include "commands.hh"

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

    queue<string> command;
    input(command);
    while(command.front() != static_cast<string>("fin"))
    {
	//cosas
	input(command);
    }
}
