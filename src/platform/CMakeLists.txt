add_library(platform STATIC course.cc courses.cc session.cc sessions.cc problem.cc problems.cc user.cc users.cc commands.cc)
set_target_properties(platform PROPERTIES VERSION 0.1)
