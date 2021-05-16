
/**
    @file
    @brief Course_repo list interface specification.

    @author Ivan Cala Mesa
    @date 15th of May of 2021

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

  The Course_repo class acts as one of the main classes. In essence, it allows an implementation-agnostic generalised use of the Evaluator main specifications.
  Course_repo class stores a repository of different @ref Course instances.
*/
class Course_repo
{
    /** @brief Container of Course instances. */
    map<int, Course> course_list;

    /**
      A Course instance is read from Standard input following the format.
	@pre Read Course instance is guaranteed to not be equal to other existing courses.
	@post If there is no Problem intersection among the Session instances contained in the created Course, it is added to the @ref Course list. Course is not added and and error message is printed in Standard output otherwise.
    */
    void read_and_add_course(Session_repo& session_list);
    /**
	@param it Iterator to the element to be listed.
	@pre @p it Is an iterator pointing to an actual, non-end, element in the container. 
	@post Information of the Course is listed on standard output following the folling format:
	course_id total_completed actual_coursing size_of_course (sessions id contained in the course)
    */
    void list_course(const decltype(course_list)::const_iterator& it) const;

    public:
        Course_repo();	
	/**
	    @brief Problem id finder inside an specific Course.
	    @param course_id The id of the specific course to find the problem in.
	    @param target_problem The id of the specific problem to be searched for.
	    @pre course_id is not equal to 0 and course_id corresponds to the id of an existing course in the implicit parameter.
	    @post If the given problem is found within the problems of the given @ref Course, the name of the Session is returned. If the problem with the given identifier does not exist in the given course, or the Course does not exist, or even the problem, an error is printed in Standard output.
	*/
	bool find_session_in_courselist(int course_id, string session_id) const;
	/** 
	    @brief An existing Course instance is inserted into the Course list.
	    @param new_course Course instance to be isnerted.
	    @pre Course instance is guaranteed to not be equal to other existing courses, and does not contain problem intersections.
	    @post @p new_course is added to the @ref Course list.
	*/

	void insert_course(Course& new_course);
	//listar por orden de inclusión
	/**
	    @brief Course Lvalue const reference getter.
	    @param course_id Identifier of a Course instance.
	    @pre @p id integer that references a valid, existing Course instance.
	    @return Lvalue reference to a Course instance
	*/
	const Course& get_course(int course_id) const;
	/**
	    @brief Course Lvalue reference getter.
	    @param id Identifier of a Course instance.
	    @pre @p id integer that references a valid, existing Course instance.
	    @return Lvalue const reference to a Course instance
	*/
	Course& get_course(int course_id);
	/**
	    @brief Reads @ref Course instances from standard input.
	    @pre Course instances in standard input follow the valid specified format by the docs.
	    @post If there is no Problem intersection among the Session instances contained in each of the read @ref Course instances individually, Course instances are added to the @ref Course list. Course is not added and an error message is printed in Standard output otherwise.
	For more insight into the reading format, see @ref Problem and @ref Session.

	*/
	void read_courses(Session_repo& session_list);
	/**
	    @brief Container size getter.
	    @pre No prerequisites.
	    @return An integer with the amount of Course instances inside the implicit parameter internal list.
	*/
	int size() const;
	/**
	    @brief Course existence checker.
	    @param course_name The id of the course to be found.
	    @pre Always true
	    @return Boolean True if @p course_name exists, False if it does not.
	*/
	bool course_exists(int course_name) const;
	/**
	    @brief Printer of Course information on every contained Course instance.
	    @pre Always true.
	    @post Course_repo are listed, sorted by their id in strict weak ordering. For each course, the displayed information is: the number of current or past users who have completed the course, the number of users currently enrolled, the number of sessions that make up the course, and the session identifiers, in the same order in which they were read when the course was created.

	*/
	void list_all_courses() const;
	/**
	    @brief Printer of Course information.
	    @param course_name The id of the course to be searched for.
	    @pre @p course_name	is the id of an existing course in the implicit parameter.
	    @post Information of the Course is listed on standard output following the folling format:
	course_id total_completed actual_coursing size_of_course (session_id1 session_id2 ...)
	*/
	void list_course(int course_name) const;
	~Course_repo();
};
#endif
