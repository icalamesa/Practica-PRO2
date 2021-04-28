#include "course.hh"
#include <iostream>

using namespace std;

Course::Course(){}

void Course::insertion(const string& ses)
{
    this->session_list.push_back(ses);
    this->session_list_ordered.emplace(ses);
}

//TO DO
bool Course::is_legal(){}

void Course::info_course() const
{
    //TO DO
    cout << "curso" << endl;
}

void Course::read_course()
{
    int n;
    cin >> n;
    string ses_ids;
    for (int i = 0; i < n; i++)
    {
	cin >> ses_ids;
	this->insertion(ses_ids);
    }
}

bool Course::session_exists(string session_id)
{
    return this->session_list_ordered.find(session_id) != this->session_list_ordered.end();
}

bool Course::find_session_in_course(string target_session) const
{
    return this->session_list_ordered.find(target_session) != this->session_list_ordered.end();
}

int Course::users_coursing() const
{
    return this->are_coursing;
}

void Course::increase_coursing()
{
    this->are_coursing++;
}

void Course::decrease_coursing()
{
    this->are_coursing--;
}

Course::~Course(){}

