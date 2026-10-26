add_executable(MiniPigInterpreter minipig.cpp)
target_include_directories(MiniPigInterpreter PUBLIC ../LibraryCPPClass)
target_link_libraries(MiniPigInterpreter LibraryCPPClass)

# Основной тест из задания
add_test(NAME Test_LW02_01 
         COMMAND MiniPigInterpreter 
         ${CMAKE_CURRENT_SOURCE_DIR}/script01.minipig 
         ${CMAKE_CURRENT_SOURCE_DIR}/input01.txt)
set_property(TEST Test_LW02_01 PROPERTY PASS_REGULAR_EXPRESSION "1 1\n1 1 1")

# Собственный тест
add_test(NAME Test_LW02_02
         COMMAND MiniPigInterpreter 
         ${CMAKE_CURRENT_SOURCE_DIR}/script02.minipig 
         ${CMAKE_CURRENT_SOURCE_DIR}/input02.txt)
set_property(TEST Test_LW02_02 PROPERTY PASS_REGULAR_EXPRESSION "42\n\n")

# Собственный тест
add_test(NAME Test_LW02_03
         COMMAND MiniPigInterpreter 
         ${CMAKE_CURRENT_SOURCE_DIR}/script03.minipig 
         ${CMAKE_CURRENT_SOURCE_DIR}/input03.txt)
set_property(TEST Test_LW02_03 PROPERTY PASS_REGULAR_EXPRESSION "7\n\n")