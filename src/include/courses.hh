
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
        @pre @p target_problem is an string correctly formatted
	    @return An std::string with the id of the internal session that contains the given problem id. If it does not exist, the string retuned is empty.
	*/
	string find_session_id(string target_problem);
    /**
        @param id String with identifier of a session
        @
    */
    Session& get_session(string id);
	Session& operator[](string);

	~Course();
};
/** @brief Interface of a repository of different courses, uniquely identified by their id.

  The Courses class acts as one of the main classes. In essence, it allows an implementation-agnostic generalised use of the Evaluator main specifications.
  Courses class stores a repository of different @ref Course instances.
*/
class Courses
{
    //listar por orden de inclusión
    map<int, Course> course_list;

    public:
    Courses();
	/**

	    @param new_course Course instance to be inserted.
        @pre @p newcourse is a valid course instance
        @post A new Course instance has been added to the @ref Course list.
	*/
	void insert_course(Course new_course);
	/**
        Reads Cours einstances from standard input.
	    @pre Course instances in standard input follow the valid specified format by the docs.
        @post Course instances have been read and added to the list of courses.
	    For more insight into the reading format, see @ref Problem and @ref Session.
	*/
	void read_courses();
    /**
        @pre No prerequisites.
        @return An integer with the amount of Course instances inside the implicit argument internal list.
    */
	int count_courses();
    /**
        @param id Identifier of a Course instance.
        @pre @p id is an integer with a valid course id.
        @return Lvalue reference to a Course instance
    */
	Course& get_course();
	Course& operator[](int index);

	~Courses();
};
#endif
