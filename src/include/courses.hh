
/** 
    @file
    @brief Course class and its list interface.
    
    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/

/** @cond */
#include <string>
/** @endcond */

#include "sessions.hh"
using namespace std;
#ifndef COURSES
#define COURSES
/** @brief Repository of @ref Session instances identified by an unique id.

    The Course class behaves as a wrapper of uniquely identified by an id combinations Session instances.
*/
class Course
{
    Sessions session_list;
    public:
	Course();
	/**
	    @return True if there is no repeated problem across the different sessions stored in the implicit parameter. False otherwise.
	*/
	bool is_legal();
	/**
	    @param target_problem The problem id to be searched.
	    @return An std::string containing the id of the internal session that contains the given problem id.
	*/
	string find_session_id(string target_problem);
	Session& operator[](string);

	~Course();
};
/** @brief Interface of a repository of different courses, uniquely identified by their id.

  The Courses class acts as one of the main classes. In essence, it allows an implementation-agnostic generalised use of the Evaluator main specifications.
  Courses class stores a repository of different @ref Course instances.
*/
class Courses
{
    //incorrecto, listar por orden de inclusion
    map<int, Course> course_list;
    public:
	/**
	    Adds a new course to the @ref Course list.
	    @param new_course Course instance to be inserted.
	*/
	void insert_course(Course new_course);
	/**
	    Reads a course instance from standard input and inserts it into the list.
	    For more insight into the reading format, see @ref Problem and @ref Session.
	*/
	void read_courses();
	void count_courses();
	Course& get_course();
	Course& operator[](int index);
	Courses();
	~Courses();
};
#endif
