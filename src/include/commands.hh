
/**
    @file
    @brief Evaluator platform main program.

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/

#include "users.hh"
#include "courses.hh"

//1.
/**
    @param problem_id Id for the new problem to be created.
    @param problem_list Problem repository to insert the new problem instance in.
    @pre No precondition.
    @post Adds a new problem with identifier @p problem_id. If a problem already existed on the platform with the same identifier, an error message is printed. Otherwise the number of problems in the collection after adding is printed.
*/
void add_problem(string problem_id, Problem_repo& problem_list);

//2.
/**
    @param session_id Id for the new Session instance to be created and inserted into the Session repository.
    @param session_list Session repository to insert the new Session instance in.
    @pre No precondition.
    @post Add a new session with identifier s. First read the problem structure of the session, in the same way as for the initial sessions (ensure that the problems exist and are not repeated). If a session already existed on the platform with the same identifier, an error message is printed. Otherwise the number of sessions is printed in the repository after adding it. It is guaranteed that the new session is not the same as the existing ones.
*/
void add_session(string session_id, Sessions& session_list);

//3.
/**
    @param course_id Id for the new Course instance to be created and inserted into the Course repository.
    @param course_list Problem repository to insert the new problem instance in.
    @pre No precondition.
    @post Adds a new course with identifier size + 1 in case it meets the constraint of no repetition of problems in the same course. The command supports the short form nc. First a number of sessions is read and then a sequence of valid session identifiers. If there are no intersection of problems in the sessions, the course is added to the course set and its identifier is printed. its identifier is printed. Otherwise, it is not added to the set (so that the size does not change) and an error message is printed. It is guaranteed that the new course is not is not the same as the existing ones.
*/
void add_course(int course_id, Courses& course_list);

//4.
/**
    @param user_id Id for the new User instance to be created and inserted into the User repository.
    @param user_list User repository to insert the new User instance in.
    @pre No precondition.
    @post Registers a new user with identifier @p user_id. If a user with the same identifier already exists on the platform, an error message is printed. Otherwise the number of registered users is printed after adding it.

*/
void add_user(string user_id, Users& user_list);

//5.
/**
    @param user_id Id for the new User instance to be created and inserted into the User repository.
    @param user_list User repository to insert the new User instance in.
    @pre No precondition.
    @post Removes a user with identifier @p user_id from the list. If there is no user on the platform with the same identifier, an error message is printed. Otherwise the number of registered users is printed after deletion. 
    
    If another user with the same name is registered later, it is as if the previous user did not exist.
*/
void remove_user(string user_id, Users& user_list);

//6.
/**
    @param user_id Id of the User.
    @param course_id Id of the Course to enroll the User in.
    @param user_list the list of users where the target user we assume is in.
    @pre No precondition.
    @post Enrolls the user with identifier @p user_id in the course with identifier @p course_id. If the user or the course does not exist in the platform or is already enrolled in another course that has not been completed, an error message is printed. Otherwise the number of users enrolled in the course after adding the course is printed (it is guaranteed that the user has not been previously enrolled in the course).
*/
void add_to_course(string user_id, int course_id, Users& user_list);

//7.
/**
    @param user_id Id of the User to be enrolled in a Course.
    @param user_list Id of the User.
    @pre No precondition.
    @post Queries the course in which the user with the identifier @p user_id is enrolled in. If the user does not exist in the platform, an error message is printed. Otherwise, the course identifier or a zero is printed if the user is not enrolled in any course.

*/
void tell_usr_course(string user_id, Users& user_list);

//8.
/**
    @param course_id Id of the Course.
    @param problem_id Id of the Problem.
    @param course_list Course instances repository.
    @param problem_list Repository of Problem instances.
    @pre No precondition.
    @post Queries the session of the problem whose identifier is @p problem_id in the course with identifier @p course_id. If the course does not exist or if the problem does not exist or if the problem does not belong to the course, an error message is printed. Otherwise, the identifier of the session where the problem occurs in the course is printed.
*/
void find_problem_session(int course_id, string problem_id, Courses& course_list, Problem_repo& problem_list);

//9.
/**
    @param user_id Id of the User.
    @param user_list Repository of User instances.
    @pre No precondition.
    @post The problems successfully solved by the user are listed in increasing order by identifier, either those existing in the course in which the user is currently enrolled (if any) or those solved in previous courses. In addition to the identifiers, the number of submissions made by the user to each problem in the list is also printed (value greater than or equal to one). If the user does not exist in the platform, an error message is printed.
*/
void tell_solved_probs(string user_id, Users& user_list);

//10.
/**
    @param user_id Id of the User.
    @param user_list Repository of User instances.
    @param course_list Repository of Course instance.
    @pre No precondition.
    @post The problems that the user has not yet solved in the course in which he is currently enrolled, but to which he can already make a submission (because he fulfills all his prerequisites, direct and indirect) are listed in increasing order by identifier. In addition to the identifiers, the number of submissions made by the user to each problem in the list (value greater than or equal to zero) is also printed. If the user does not exist in the platform or is not enrolled in any course, an error message is printed.
*/
void tell_solvable_probs(string user_id, Users& user_list, Courses& course_list);

//11.
/**
    @param user_id Id of the User that performed the submission.
    @param problem_id Id of the Problem submitted.
    @param successful True if the submission is flagged correct, false otherwise.
    @pre It is ensured that the User whose identifier is @p user_id is registered and enrolled in a course where the problem appears and that the problem belongs to the set of problems to which he can submit a solution by fulfilling the prerequisites.
    @post The outcome (r= 1 if success or= 0 if failure) of a user's new submission to the problem is noted. All submissions result in updating the statistics of the user and the problem. In addition, in case= 1 it is also necessary to update the user's solved and submittable problems and check if he has completed the course he was enrolled in. If completed, the user is no longer enrolled in the course.
*/
void deliver_problem(string user_id, string problem_id, bool successful);

//12.
/**
    @param problem_list Repository of Problem instances.
    @pre No precondition.
    @post The problems in the collection are listed, indicating for each problem the number of total submissions and the number of successful submissions to that problem, in both cases from present or past users. The ratio (successful_submissions+ 1)/(total_submissions+ 1) should also be written, and the problems should be listed in increasing order by this ratio. In case of a tie, they should be listed in increasing order of identifier.
*/
void tell_prob_list(Problem_repo& problem_list);
/**
    @param problem_id Id of the specific Problem instance.
    @param problem_list Repository of Problem instances.
    @pre No precondition.
    @post The information of the problem whose identifier is @p problem_id is listed (if it exists), indicating the number of total submissions and the number of successful submissions to that problem, in both cases from present or past users. The ratio (successful_submissions+ 1)/(total_submissions+ 1) should also be written. If @p problem_id does not exist in the platform an error message is printed.
*/
void tell_prob_list(string problem_id, Problem_repo& problem_list);

//13.
/**
    @param session_list Repository of Session instances.
    @pre No precondition.
    @post The current sessions of the platform are listed, sorted in increasing order by their identifier and showing, for each session, the number of problems that form it and the identifiers of these problems, following their prerequisite structure in post order.
*/
void tell_session(Sessions& session_list);
/**
    @param session_id Id of the specific Session instance.
    @param session_list Repository of Session instances.
    @pre Information of the session whose identifier is @p session_id is displayed: the number of problems that form it and the identifiers of these problems, following its prerequisite structure in post order.
*/
void tell_session(string session_id, Sessions& session_list);

//14.
/**
    @param course_list Repository of Course instances.
    @pre No precondition.
    @post The current courses on the platform are listed, sorted incrementally by course identifier and showing, for each course, the number of current or past users who have completed the course, the number of users currently enrolled, the number of sessions that make up the course and the session identifiers, in the same order in which they were read when the course was created.
*/
void tell_courses(Courses& course_list);
/**
    @param course_id Id of the specific Course instance.
    @param course_list Repository of Course instances.
    @pre No precondition.
    @post Information about the course whose identifier is @p course_id is displayed (if it exists): the number of current or past users who have completed it, the number of users currently enrolled, the number of sessions that make it up and the session identifiers, in the same order in which they were read when the course was created. If it does not exist in the platform, an error message is printed. 
*/
void tell_courses(int course_id, Courses& course_list);

//15.
void tell_users();
void tell_users(string user_id);
/**
    @param problem_list The repository of @ref Problem instances where all problems in the program lie.
    @param session_list The repository of @ref Session instances where all sessions in the program lie.
    @param course_list The repository of @ref Course instances where all courses in the program lie.
    
    Initializes @p problem_list, @p session_list and @p course_list (in that order) by calling at their internal reading methods. The initializations require reading from Standard input.
    @pre Standard input text follows the input format for @ref Problem_repo, @ref Courses, and @ref Users.
    @post Internal container interfaces have been initialized with their respective contained objects.
*/
    void init(Problem_repo& problem_list, Sessions& session_list, Courses& course_list);
/**
    Starts a command-line mode. Executes commands depending on the input. Abbrevations for every commad have been defined.
*/
    void console(Problem_repo& problem_list, Sessions& session_list, Courses& course_list);
