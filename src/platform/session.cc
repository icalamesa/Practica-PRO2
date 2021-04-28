#include "session.hh"
#include <iostream>

using namespace std;

Session::Session(){}
Session::~Session(){}
Session::Session(string session_id)
{
    this->id = id;
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

bool Session::find(string target_problem) const
{
    return search_problem(this->problem_node, target_problem);
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
    }
}

void Session::read_session()
{
    cin >> this->id;
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
    cout << this->get_id() << ' ';
    print_session(this->problem_node);
    cout << endl;
}

int Session::size() const
{
    return this->list_of_problems.size();
}
