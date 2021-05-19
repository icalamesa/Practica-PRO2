#include "course.hh"
#include <iostream>

using namespace std;

Course::Course(){}

void Course::session_insertion(const string& session_id)
{
    //need to push it on both lists.
    this->session_list.push_back(session_id);
    this->session_list_ordered.insert(session_id);
}

int Course::size() const
{
    return this->session_list.size();
}

int Course::amount_problems() const
{
    return problem_set.size();
}

bool Course::is_legal()
{
    return this->problem_set.size() == this->expected_size;
}

void Course::info_course() const
{
    cout << '(';
    for(auto i = session_list.cbegin(); i != this->session_list.cend(); ++i)
    {
	//I perform this weird (and inefficient) operation because I need 
	//a way to NOT print an extra space in the last element of the list
	//example of what is being avoided: (a b c )
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

void Course::read_course(const Session_repo& session_list)
{
    int n;
    cin >> n;
    string ses_ids;
    vector<string> probs;
    //here it is reading the many different sessions that form the Course.
    for (int i = 0; i < n; i++)
    {
	cin >> ses_ids;
	//insert them in the Course
	this->session_insertion(ses_ids);
	const Session& ses = session_list.get_session(ses_ids);
	
	//It will fetch the different problems that form a Session 
	int session_size = ses.size();
	for (int j = 0; j < session_size; j++)
	{
	    string problem = ses.get_i_problem(j);
	    probs.push_back(problem);
	}
    }
    //and push them to the Course altogether
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

//this is a vector-like index-based session getter
string Course::get_session_id(int i) const
{
    return this->session_list[i];
}

//this is a vector-like index-based problem getter
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

string Course::session_of_problem(const string& problem_id, const Session_repo& session_list)
{
    //brute force to find the Session of a Problem. Not the best method.
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

void Course::init_solvable_from_sessions(Session_repo& session_list, const string& user_id, User_repo& user_list)
{
    //this is the internal session_list container. Do not get confused.
    for (const auto& session : this->session_list)
    {
	//one by one, we set everything so that the User gets every different possible
	//solvable problem from every different session inserted into its solvable problems list.
	session_list.get_session(session).init_solvable_problems_from_user(user_id, user_list);

    }
}

Course::~Course(){}

