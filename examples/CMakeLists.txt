# да блин почему тесты не работают((

add_executable(${PROJECT_NAME}_example_01 example_01.cpp)
target_include_directories(${PROJECT_NAME}_example_01 PUBLIC ../include)
target_link_libraries(${PROJECT_NAME}_example_01 ${PROJECT_NAME})
