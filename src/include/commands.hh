
/**
    @file
    @brief Evaluator platform main program.

    This file contains the multiple different functions used for every operation that may be performed by the user-agent. In the Evaluator platform's implementation, every different function/function overload is 1:1 identified by a single command (plus its correspondent abbreviation).

    @author Ivan Cala Mesa
    @date 1st of April of 2021

*/

#include "users.hh"
#include "courses.hh"

//1.
/**
    @param problem_id Id for the new problem to be created.
    @param problem_list Problem repository to insert the new problem instance in.
    @pre Always true.
    @post Adds a new problem with identifier @p problem_id. If a problem already existed on the platform with the same identifier, an error message is printed. Otherwise the number of problems in the collection after adding is printed.
*/
void add_problem(Problem_repo& problem_list, const string& problem_id);

//2.
/**
    @param session_id Id for the new Session instance to be created and inserted into the Session repository.
    @param session_list Session repository to insert the new Session instance in.
    @pre Always true.
    @post Add a new session with identifier s. First read the problem structure of the session, in the same way as for the initial sessions (ensure that the problems exist and are not repeated). If a session already existed on the platform with the same identifier, an error message is printed. Otherwise the number of sessions is printed in the repository after adding it. It is guaranteed that the new session is not the same as the existing ones.
*/
void add_session(Session_repo& session_list, const string& session_id);

//3.
/**
    @param course_id Id for the new Course instance to be created and inserted into the Course repository.
    @param course_list Problem repository to insert the new problem instance in.
    @pre Always true.
    @post Adds a new course with identifier size + 1 in case it meets the constraint of no repetition of problems in the same course. The command supports the short form nc. First a number of sessions is read and then a sequence of valid session identifiers. If there are no intersection of problems in the sessions, the course is added to the course set and its identifier is printed. its identifier is printed. Otherwise, it is not added to the set (so that the size does not change) and an error message is printed. It is guaranteed that the new course is not is not the same as the existing ones.
*/
void add_course(Course_repo& course_list, Session_repo& session_list);

//4.
/**
    @param user_id Id for the new User instance to be created and inserted into the User repository.
    @param user_list User repository to insert the new User instance in.
    @pre Always true.
    @post Registers a new user with identifier @p user_id. If a user with the same identifier already exists on the platform, an error message is printed. Otherwise the number of registered users is printed after adding it.

*/
void add_user(string user_id, User_repo& user_list);

//5.
/**
    @param user_id Id for the new User instance to be created and inserted into the User repository.
    @param user_list User repository to insert the new User instance in.
    @pre Always true.
    @post Removes a user with identifier @p user_id from the list. If there is no user on the platform with the same identifier, an error message is printed. Otherwise the number of registered users is printed after deletion. 
    
    If another user with the same name is registered later, it is as if the previous user did not exist.
*/
void remove_user(string user_id, User_repo& user_list, Course_repo& course_list);

//6.
/**
    @param user_id Id of the User.
    @param course_id Id of the Course to enroll the User in.
    @param user_list the list of users where the target user we assume is in.
    @pre Always true.
    @post Enrolls the user with identifier @p user_id in the course with identifier @p course_id. If the user or the course does not exist in the platform or is already enrolled in another course that has not been completed, an error message is printed. Otherwise the number of users enrolled in the course after adding the course is printed (it is guaranteed that the user has not been previously enrolled in the course).
*/
void sign_in_course(string user_id, int course_id, User_repo& user_list, Course_repo& course_list, Session_repo& session_list);

//7.
/**
    @param user_id Id of the User to be enrolled in a Course.
    @param user_list Id of the User.
    @pre Always true.
    @post Queries the course in which the user with the identifier @p user_id is enrolled in. If the user does not exist in the platform, an error message is printed. Otherwise, the course identifier or a zero is printed if the user is not enrolled in any course.

*/
void tell_usr_course(string user_id, User_repo& user_list);

//8.
/**
    @param course_id Id of the Course.
    @param problem_id Id of the Problem.
    @param course_list Course instances repository.
    @param problem_list Repository of Problem instances.
    @pre Always true.
    @post Queries the session of the problem whose identifier is @p problem_id in the course with identifier @p course_id. If the course does not exist or if the problem does not exist or if the problem does not belong to the course, an error message is printed. Otherwise, the identifier of the session where the problem occurs in the course is printed.
*/
void find_problem_session(int course_id, string problem_id, Course_repo& course_list, Problem_repo& problem_list, Session_repo& session_list);

//9.
/**
    @param user_id Id of the User.
    @param user_list Repository of User instances.
    @pre Always true.
    @post The problems successfully solved by the user are listed in increasing order by identifier, either those existing in the course in which the user is currently enrolled (if any) or those solved in previous courses. In addition to the identifiers, the number of submissions made by the user to each problem in the list is also printed (value greater than or equal to one). If the user does not exist in the platform, an error message is printed.
*/
void tell_solved_probs(string user_id, User_repo& user_list);

//10.
/**
    @param user_id Id of the User.
    @param user_list Repository of User instances.
    @param course_list Repository of Course instance.
    @pre Always true.
    @post The problems that the user has not yet solved in the course in which he is currently enrolled, but to which he can already make a submission (because he fulfills all his prerequisites, direct and indirect) are listed in increasing order by identifier. In addition to the identifiers, the number of submissions made by the user to each problem in the list (value greater than or equal to zero) is also printed. If the user does not exist in the platform or is not enrolled in any course, an error message is printed.
*/
void tell_solvable_probs(string user_id, User_repo& user_list, Course_repo& course_list);

//11.
/**
    @param user_id Id of the User that performed the submission.
    @param problem_id Id of the Problem submitted.
    @param successful True if the submission is flagged correct, false otherwise.
    @pre It is ensured that the User whose identifier is @p user_id is registered and enrolled in a course where the problem appears and that the problem belongs to the set of problems to which he can submit a solution by fulfilling the prerequisites.
    @post The outcome (r= 1 if success or= 0 if failure) of a user's new submission to the problem is noted. All submissions result in updating the statistics of the user and the problem. In addition, in case= 1 it is also necessary to update the user's solved and submittable problems and check if he has completed the course he was enrolled in. If completed, the user is no longer enrolled in the course.
*/
void deliver_problem(string user_id, string problem_id, bool successful, User_repo& user_list, Problem_repo& problem_list, Session_repo& session_list, Course_repo& course_list);

//12.
/**
    @param problem_list Repository of Problem instances.
    @pre Always true.
    @post The problems in the collection are listed, indicating for each problem the number of total submissions and the number of successful submissions to that problem, in both cases from present or past users. The ratio (successful_submissions+ 1)/(total_submissions+ 1) should also be written, and the problems should be listed in increasing order by this ratio. In case of a tie, they should be listed in increasing order of identifier.
*/
void tell_prob_list(Problem_repo& problem_list);
/**
    @param problem_id Id of the specific Problem instance.
    @param problem_list Repository of Problem instances.
    @pre Always true.
    @post The information of the problem whose identifier is @p problem_id is listed (if it exists), indicating the number of total submissions and the number of successful submissions to that problem, in both cases from present or past users. The ratio (successful_submissions+ 1)/(total_submissions+ 1) should also be written. If @p problem_id does not exist in the platform an error message is printed.
*/
void tell_prob_list(string problem_id, Problem_repo& problem_list);

//13.
/**
    @param session_list Repository of Session instances.
    @pre Always true.
    @post The current sessions of the platform are listed, sorted in increasing order by their identifier and showing, for each session, the number of problems that form it and the identifiers of these problems, following their prerequisite structure in post order.
*/
void tell_session(const Session_repo& session_list);
/**
    @param session_id Id of the specific Session instance.
    @param session_list Repository of Session instances.
    @pre Information of the session whose identifier is @p session_id is displayed: the number of problems that form it and the identifiers of these problems, following its prerequisite structure in post order.
*/
void tell_session(const string& session_id, const Session_repo& session_list);

//14.
/**
    @param course_list Repository of Course instances.
    @pre Always true.
    @post The current courses on the platform are listed, sorted incrementally by course identifier and showing, for each course, the number of current or past users who have completed the course, the number of users currently enrolled, the number of sessions that make up the course and the session identifiers, in the same order in which they were read when the course was created.
*/
void tell_courses(Course_repo& course_list);
/**
    @param course_id Id of the specific Course instance.
    @param course_list Repository of Course instances.
    @pre Always true.
    @post Information about the course whose identifier is @p course_id is displayed (if it exists): the number of current or past users who have completed it, the number of users currently enrolled, the number of sessions that make it up and the session identifiers, in the same order in which they were read when the course was created. If it does not exist in the platform, an error message is printed. 
*/
void tell_courses(int course_id, Course_repo& course_list);

//15.
/**
    @param user_list Repository of User instances.
    @pre Always true.
    @post The users currently registered on the platform are listed, sorted in ascending order by name and showing, for each user, how many total submissions they have made, how many problems they have successfully resolved, how many problems they have attempted to resolve (at least one submission), and the course identifier of the course they are enrolled in or a zero if they are not enrolled in any.
*/
void tell_users(User_repo& user_list);
/**
    @param user_id Id of the specific User instance.
    @param user_list Repository of User instances.
    @pre Always true.
    @post Information about a User whose identifier is @p user_id is displayed (if it exists): how many total submissions he has made, how many problems he has successfully solved, how many problems he has attempted to solve (at least one submission), and the identifier of the course he is enrolled in or a zero if he is not enrolled in any. If the user does not exist on the platform an error message is printed.
*/
void tell_users(string user_id, User_repo& user_list);

