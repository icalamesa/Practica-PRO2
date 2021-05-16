#include "courses.hh"
#include <iostream>

Course_repo::Course_repo(){}
Course_repo::~Course_repo(){}

const Course& Course_repo::get_course(int course_id) const
{
    return this->course_list.at(course_id);
}

Course& Course_repo::get_course(int course_id)
{
    return this->course_list.at(course_id);
}

bool Course_repo::find_session_in_courselist(int course_id, string session_id) const
{
    return this->get_course(course_id).session_exists(session_id);
}

void Course_repo::read_and_add_course(Session_repo& session_list)
{
    Course new_course;
    new_course.read_course(session_list);
    this->insert_course(new_course);
}

void Course_repo::insert_course(Course& new_course)
{
    int num = this->size();
    num++;
    
    this->course_list.insert(make_pair(num, new_course));
}

void Course_repo::read_courses(Session_repo& session_list)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
	this->read_and_add_course(session_list);
    }
}

int Course_repo::size() const
{
    return this->course_list.size();
}

void Course_repo::list_all_courses() const
{
    for (auto it = this->course_list.begin(); it != this->course_list.end(); it++)
    {
	this->list_course(it);
    }
}

void Course_repo::list_course(const map<int, Course>::const_iterator& it) const
{
    cout << it->first << ' '; //this one is the id
    cout << it->second.have_completed() << ' ';
    cout << it->second.users_coursing() << ' ';
    cout << it->second.size() << ' ';
    it->second.info_course();
}

void Course_repo::list_course(int course_name) const
{
    //NOTE: when std::map::find is const called, the returned type is
    //const iterator.
    auto it = this->course_list.find(course_name);
    this->list_course(it);
}

bool Course_repo::course_exists(int course_name) const
{
    return this->course_list.find(course_name) != this->course_list.end();
}

