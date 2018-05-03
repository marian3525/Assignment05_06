cmake_minimum_required(VERSION 3.9)
project(Assignment05_06)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment05_06 main.cpp repository/DynamicVector.cpp repository/DynamicVector.h repository/repository.cpp repository/repository.h controller/controller.cpp controller/controller.h ui/cli.cpp ui/cli.h domain/tutorial.cpp domain/tutorial.h tests/test.cpp tests/test.h Validator/Validator.cpp Validator/Validator.h repository/TemplateDynamicVector.cpp repository/TemplateDynamicVector.h Exceptions/RepositoryException.cpp Exceptions/RepositoryException.h Exceptions/ValidatorException.cpp Exceptions/ValidatorException.h Exceptions/ControllerException.cpp Exceptions/ControllerException.h)