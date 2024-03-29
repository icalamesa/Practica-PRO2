#include "session.hh"
#include <iostream>

using namespace std;

Session::Session(){}
Session::~Session(){}
Session::Session(const string& session_id)
{
    this->id = session_id;
}

/** @brief Comparison of ids with <*/
bool Session::operator< (const Session& other) const
{
    return this->get_id() < other.get_id();
}

/** @brief Comparison of ids with ==*/
bool Session::operator== (const Session& other) const
{
    return this->get_id() == other.get_id();
}

string Session::get_id() const
{
    return this->id;
}

bool Session::find(const string& target_problem) const
{
    return this->tree_map.find(target_problem) != this->tree_map.end();
}

void Session::fill_problem_set(BinTree<string>& tree)
{
    string aux;
    cin >> aux;
    if (aux != "0")
    {
	BinTree<string> left, right;
	fill_problem_set(left);
	fill_problem_set(right);
	tree = BinTree<string>(aux, left, right);
	//we also want to insert them in the map (tree_map)
	string l = "0";
	string r = "0";
	if (not left.empty()) l = left.value();
	if (not right.empty()) r = right.value();
	this->tree_map.insert(make_pair(aux, make_pair(l, r)));
	this->problems.push_back(aux);
    }
}

void Session::read_session()
{
    cin >> this->id;
    fill_problem_set(this->problem_node);
}

void Session::read_session_problems()
{
    fill_problem_set(this->problem_node);
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
    return this->tree_map.size();
}

string Session::get_i_problem(int i) const
{
    auto a = this->tree_map.begin();
    return this->problems[i];
}

void Session::problem_fetching(User& usr, const string& problem_id)
{
    //this fetches solvable problems for the user. But it does NOT
    //use the BinTree. Instead, it makes use of a std::map (tree_map).
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
void Session::immersion_init_solvable_problems_from_user(User& usr, const BinTree<string>& tree)
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
	    immersion_init_solvable_problems_from_user(usr, tree.left());
	}
	if (not tree.right().empty())
	{
	    immersion_init_solvable_problems_from_user(usr, tree.right());
	}
    }
}

//push solvable problems
void Session::init_solvable_problems_from_user(const string& user_id, User_repo& user_list)
{
    auto& usr = user_list.get_user(user_id);
    immersion_init_solvable_problems_from_user(usr, this->problem_node);
}

