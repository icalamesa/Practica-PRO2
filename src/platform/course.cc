#include "course.hh"
#include <iostream>

using namespace std;

Course::Course(){}

void Course::insertion(const string& ses)
{
    this->session_list.push_back(ses);
    this->session_list_ordered.insert(ses);
}

int Course::size() const
{
    return this->session_list.size();
}

//TO DO
bool Course::is_legal()
{
    return this->problem_set.size() == this->expected_size;
}

//THIS METHOD ONLY PRINTS SESSION IDS
void Course::info_course() const
{
    for (const auto& session : this->session_list)
    {
	cout << session << ' ';
    }
    cout << endl;
    cout << this->problem_set.size();
    for (const auto& str : this->problem_set)
    {
	cout << str << ' ';
    }
    cout << endl;
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
int Course::historical_users() const
{
    return this->have_coursed;
}

void Course::increase_coursing()
{
    this->are_coursing++;
    this->have_coursed++;
}

void Course::decrease_coursing()
{
    this->are_coursing--;
}

string Course::get_session_id(int i) const
{
    return this->session_list[i];
}

void Course::insert_problem(const string& problem_id)
{
    this->problem_set.insert(problem_id);
    this->expected_size++;
}

Course::~Course(){}

