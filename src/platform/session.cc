#include "session.hh"
#include <iostream>

using namespace std;

Session::Session(){}
Session::~Session(){}
Session::Session(const string& session_id)
{
    this->id = session_id;
}

bool Session::operator< (const Session& other) const
{
    return this->get_id() < other.get_id();
}

bool Session::operator== (const Session& other) const
{
    return this->get_id() == other.get_id();
}

string Session::get_id() const
{
    return this->id;
}

bool Session::search_problem(const BinTree<string>& tree, string& target_problem) const
{
    if (not tree.empty())
    {
	if (tree.value() == target_problem)
	{
	    return true;
	}
	else
	{
	    return search_problem(tree.left(), target_problem) or search_problem(tree.right(), target_problem);
	}
    }
    return false;
}

bool Session::find(const string& target_problem) const
{
    return this->list_of_problems.find(target_problem) != this->list_of_problems.end();
}

void Session::fill_problem_set(BinTree<string>& tree)
{
    string aux;
    cin >> aux;
    if (aux != "0")
    {
	this->list_of_problems.insert(aux);
	BinTree<string> left, right;
	fill_problem_set(left);
	fill_problem_set(right);
	tree = BinTree<string>(aux, left, right);
	string l = "0";
	string r = "0";
	if (not left.empty()) l = left.value();
	if (not right.empty()) r = right.value();
	this->tree_map.insert(make_pair(aux, make_pair(l, r)));
    }
}

void Session::read_session()
{
    cin >> this->id;
    fill_problem_set(problem_node);
}

void Session::read_session_problems()
{
    fill_problem_set(problem_node);
}

void Session::print_session(const BinTree<string>& tree) const
{
    cout << '(';
    if (not tree.left().empty())
    {
	this->print_session(tree.left());
    }
    if (not tree.right().empty())
    {
	this->print_session(tree.right());
    }
    cout << tree.value();
    cout << ')';
}

void Session::info_session() const
{
    cout << this->get_id() << ' ' << this->size() << ' ';
    this->print_session(this->problem_node);
    cout << endl;
}

int Session::size() const
{
    return this->list_of_problems.size();
}

string Session::get_i_problem(int i) const
{
    auto a = this->list_of_problems.begin();
    std::advance(a, i);
    /*for (const auto& str : this->list_of_problems)
    {
	cout << str << ' ';
    }*/
    return *a;

    //std::advance(it, i);
}

string Session::get_first_problem_id() const
{
    return problem_node.value();
}

//we assume problem_id is never incorrect
pair<string, string> Session::get_next_problems(const string& problem_id) const
{
    //cout << "llego" << endl;
    //cout << problem_id << endl;
    return this->tree_map.at(problem_id);
}

void Session::problem_fetching(User& usr, const string& problem_id)
{
    auto it = this->tree_map.find(problem_id);
    string problem1 = it->second.first;
    string problem2 = it->second.second;
    if (problem1 != "0")
    {
	if(usr.u_has_solved_problem(problem1))
	{
	    problem_fetching(usr, problem1);
	}
	else
	{
	    usr.insert_solvable(problem1);
	}
    }    
    if (problem2 != "0")
    {
	if(usr.u_has_solved_problem(problem2))
	{
	    problem_fetching(usr, problem2);
	}
	else
	{
	    usr.insert_solvable(problem2);
	}
    }
}
void Session::initial_problem_fetching(User& usr, const BinTree<string>& tree)
{
    //we assume we never enter empty problems
    if (not usr.u_has_solved_problem(tree.value()))
    {
	usr.insert_solvable(tree.value());
    }
    else
    {
	if (not tree.left().empty())
	{
	    initial_problem_fetching(usr, tree.left());
	}
	if (not tree.right().empty())
	{
	    initial_problem_fetching(usr, tree.right());
	}
    }
}

//push solvable problems
void Session::init_solvable_problems_from_user(const string& user_id, Users& user_list)
{
    auto& usr = user_list.get_user(user_id);
    initial_problem_fetching(usr, this->problem_node);
}
    //pair<string, string> solvable_candidates;
    //int course_size = course_list.course_size(this->u_tell_course());
    //string target_session_id;
    //for (int i = 0; i < course_size; i++)
    //{
	//target_session_id = course_list.get_session_id(this->u_tell_course(), i);
	//if (session_list.get_session(target_session_id).find(problem_id))
	//{
	    //break;
	//}
    //}
    //solvable_candidates = session_list.get_next_problems(target_session_id, problem_id);
    //if (solvable_candidates.first != string("0"))
    //{
	//this->insert_solvable(solvable_candidates.first);
    //}

    //if (solvable_candidates.second != string("0"))
    //{
	//this->insert_solvable(solvable_candidates.second);
    //}

    //if (this->solvable.empty())
    //{
	//course_list.decrease_coursing(this->coursing);
	//course_list.increase_completed(this->coursing);
	//this->coursing = 0;
    //}

