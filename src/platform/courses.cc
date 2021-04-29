#include "courses.hh"
#include <iostream>

Courses::Courses(){}
Courses::~Courses(){}

const Course& Courses::get_course(const int& course_id) const
{
    cout << "DEBUG GET COURSE: " << course_id << endl;
    return this->course_list[course_id];
}

Course& Courses::get_course(const int& course_id)
{
    cout << "DEBUG GET COURSE: " << course_id << endl;
    return this->course_list[course_id];
}

bool Courses::find_session_in_courselist(int course_id, string session_id) const
{
    return this->get_course(course_id).find_session_in_course(session_id);
}

void Courses::read_and_add_course()
{
    Course new_course;
    new_course.read_course();
    this->insert_course(new_course);
}

void Courses::insert_course(Course& new_course)
{
    int num = this->size();
    num++;
    
    this->course_list.insert(make_pair(num, new_course));
}

void Courses::read_courses()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
	this->read_and_add_course();
    }
}

int Courses::size() const
{
    return this->course_list.size();
}

void Courses::list_all_courses() const
{
    for (const auto& course_kv : this->course_list)
    {
	course_kv.second.info_course();
    }
}

void Courses::list_course(int course_name) const
{
    this->get_course(course_name).info_course();
}

bool Courses::course_exists(int course_name) const
{
    return this->course_list.find(course_name) != this->course_list.end();
}

int Courses::are_coursing(const int& course_id) const
{
    return this->get_course(course_id).users_coursing();
}

int Courses::historical_users(const int& course_id) const
{
    this->get_course(course_id).historical_users();
}

void Courses::increase_coursing(const int& course_id)
{
    this->get_course(course_id).increase_coursing();
}

void Courses::decrease_coursing(const int& course_id)
{
    this->get_course(course_id).decrease_coursing();
}

int Courses::course_size(int course_id) const
{
    this->get_course(course_id).size();
}

void Courses::print_course_sessions(int course_id) const
{
    this->get_course(course_id).info_course();
}
