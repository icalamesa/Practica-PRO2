
/**
    @file
    @brief Courses list interface specification.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/

/** @cond */
#include <string>
#include <map>
/** @endcond */
#include "course.hh"
using namespace std;
#ifndef COURSES_HH
#define COURSES_HH
/** @brief Interface of a repository of different courses, uniquely identified by their id.

  The Courses class acts as one of the main classes. In essence, it allows an implementation-agnostic generalised use of the Evaluator main specifications.
  Courses class stores a repository of different @ref Course instances.
*/
class Courses
{
    map<int, Course> course_list;

    /**
      A Course instance is read from Standard input following the format.
	@pre Read Course instance is guaranteed to not be equal to other existing courses.
	@post If there is no Problem intersection among the Session instances contained in the created Course, it is added to the @ref Course list. Course is not added and and error message is printed in Standard output otherwise.
    */
    void read_and_add_course();

    Course& operator[](int index) const;
    void list_course(decltype(course_list)::const_iterator& it) const;

    public:
        Courses();	
	/**
	    @param course_id The id of the specific course to find the problem in.
	    @param target_problem The id of the specific problem to be searched for.
	    @pre course_id is not equal to 0 and course_id corresponds to the id of an actual course in the implicit parameter.
	    @post If the given problem is found within the problems of the given @ref Course, the name of the Session is returned. If the problem with the given identifier does not exist in the given course, or the Course does not exist, or even the problem, an error is printed in Standard output.
	*/
	bool find_session_in_courselist(int course_id, string session_id) const;
	/** COMPROBAR ESTA
	  An existing Course instance is inserted into the Course list.
	    @pre Course instance is guaranteed to not be equal to other existing courses.
	    @post If there is no Problem intersection among the Session instances contained in the created Course, it is added to the @ref Course list. Course is not added and and error message is printed in Standard output otherwise.
	*/

	void insert_course(Course& new_course);
	//listar por orden de inclusión
	/**
	    @param id Identifier of a Course instance.
	    @pre @p id is an integer with a valid course id.
	    @return Lvalue reference to a Course instance
	*/
	const Course& get_course(const int& id) const;
	//NECESITA DOXYCOMENTARIOS
	Course& get_course(const int& course_id);
	/**
        Reads @ref Course instances from standard input.
	    @pre Course instances in standard input follow the valid specified format by the docs.
	    @post If there is no Problem intersection among the Session instances contained in each of the read @ref Course instances individually, Course instances are added to the @ref Course list. Course is not added and an error message is printed in Standard output otherwise.
	For more insight into the reading format, see @ref Problem and @ref Session.

	*/
	void read_courses();
	/**
	    @pre No prerequisites.
	    @return An integer with the amount of Course instances inside the implicit parameter internal list.
	*/
	int size() const;
	/**
	    @param course_name The id of the course to be found.
	    @pre No precondition
	    @return Boolean True if @p course_name exists, False if it does not.
	*/
	bool course_exists(int course_name) const;
	/**
	    @pre No precondition.
	    @post Courses are listed, sorted by their id in strict weak ordering. For each course, the displayed information is: the number of current or past users who have completed the course, the number of users currently enrolled, the number of sessions that make up the course, and the session identifiers, in the same order in which they were read when the course was created.

	*/
	void list_all_courses() const;
	/**
	    @param course_name The id of the course to be searched for.
	    @pre No precondition.
	    @post If the course exists, lists information for a single course. That information is: The number of current or past users who have completed the course, the number of users currently enrolled, the number of sessions that make up the course, and the session identifiers, in the same order in which they were read when the course was created. \n If the course does not exist, prints an error message in Standard output.
	*/
	void list_course(int course_name) const;
	void increase_coursing(const int& course_id);
	void decrease_coursing(const int& course_id);
	int are_coursing(const int& course_id) const;
	int historical_users(const int& course_id) const;
	int course_size(int course_id) const;
	void print_course_sessions(int course_id) const;
	string get_session_id(int course_id, int i) const;
	~Courses();
};
#endif
