# Задача 1: Подсчет оценок
add_executable(LW01_01 01.cpp)
target_include_directories(LW01_01 PUBLIC ../LibraryCPPClass)
target_link_libraries(LW01_01 LibraryCPPClass)

# Задача 2: Сжатие массива
add_executable(LW01_02 02.cpp)
target_include_directories(LW01_02 PUBLIC ../LibraryCPPClass)
target_link_libraries(LW01_02 LibraryCPPClass)

# Тесты для первой программы (01.cpp)
add_test(NAME Test_LW01_01_1 COMMAND LW01_01 ${CMAKE_CURRENT_SOURCE_DIR}/input01.01.txt)
set_property(TEST Test_LW01_01_1 PROPERTY PASS_REGULAR_EXPRESSION "5: 3, 4: 2, 3: 1, 2: 2")

add_test(NAME Test_LW01_01_2 COMMAND LW01_01 ${CMAKE_CURRENT_SOURCE_DIR}/input01.02.txt)
set_property(TEST Test_LW01_01_2 PROPERTY PASS_REGULAR_EXPRESSION "5: 5, 4: 0, 3: 0, 2: 0")

# Тесты для второй программы (02.cpp) с передачей интервала [a, b]
add_test(NAME Test_LW01_02_1 COMMAND LW01_02 ${CMAKE_CURRENT_SOURCE_DIR}/input02.01.txt 3 5)
set_property(TEST Test_LW01_02_1 PROPERTY PASS_REGULAR_EXPRESSION "1 8 2 10 0 0 0")

add_test(NAME Test_LW01_02_2 COMMAND LW01_02 ${CMAKE_CURRENT_SOURCE_DIR}/input02.02.txt 25 45)
set_property(TEST Test_LW01_02_2 PROPERTY PASS_REGULAR_EXPRESSION "10 20 50 60 0 0")