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

int Course::amount_problems() const
{
    return problem_set.size();
}

//TO DO
bool Course::is_legal()
{
    return this->problem_set.size() == this->expected_size;
}

//THIS METHOD ONLY PRINTS SESSION IDS
void Course::info_course() const
{
    cout << '(';
    for(auto i = session_list.cbegin(); i != this->session_list.cend(); ++i)
    {
        std::cout << *i;
        auto aux = i;
        if(++aux != this->session_list.cend())
	{
            std::cout << " ";
        }
    }
    cout << ')';
    cout << endl;
}

void Course::read_course(const Sessions& session_list)
{
    int n;
    cin >> n;
    string ses_ids;
    for (int i = 0; i < n; i++)
    {
	cin >> ses_ids;
	this->insertion(ses_ids);
    }
    vector<string> probs;
    int course_size = this->size();
    for (int i = 0; i < course_size; i++)
    {
	string target_session = this->get_session_id(i);
	//int session_size = session_list.session_size(target_session);
	auto& ses = session_list.get_session(target_session);
	int session_size = ses.size();
	for (int j = 0; j < session_size; j++)
	{
	    string problem = ses.get_i_problem(j);
	    probs.push_back(problem);
	}
    }
    for ( const auto& str : probs )
    {
	this->insert_problem(str);
    }
}

bool Course::session_exists(const string& session_id) const
{
    return this->session_list_ordered.find(session_id) != this->session_list_ordered.end();
}

int Course::users_coursing() const
{
    return this->are_coursing;
}
int Course::have_completed() const
{
    return this->have_coursed;
}

void Course::increase_coursing()
{
    this->are_coursing++;
}

void Course::increase_completed()
{
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

string Course::get_problem_id(int i) const
{
    auto it = this->problem_set.begin();
    std::advance(it, i);
    return *it;
}

void Course::insert_problem(const string& problem_id)
{
    this->problem_set.insert(problem_id);
    this->expected_size++;
}

bool Course::find_problem(const string& problem_id) const
{
    return this->problem_set.find(problem_id) != this->problem_set.end();
}

string Course::session_of_problem(const string& problem_id, const Sessions& session_list)
{
    for (const auto& session_id : this->session_list)
    {
	auto& the_session = session_list.get_session(session_id);
	if (the_session.find(problem_id))
	{
	    return session_id;
	}
    }
    return string("0");
}

void Course::init_solvable_from_sessions(Sessions& session_list, const string& user_id, Users& user_list)
{
    //this is the internal session_list. Do not get confused.
    for (const auto& session : this->session_list)
    {
	session_list.get_session(session).init_solvable_problems_from_user(user_id, user_list);

    }
}

Course::~Course(){}

