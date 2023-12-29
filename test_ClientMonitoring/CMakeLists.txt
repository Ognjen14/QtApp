include_directories(${CMAKE_SOURCE_DIR})

function(SETUP_TESTS)
       foreach(_testname ${ARGN})
           add_executable(${_testname} tst_${_testname}.cpp )
           add_test(NAME ${_testname} COMMAND ${_testname})
           target_link_libraries(${_testname} Qt${QT_MAJOR_VERISION}::Test ClientMonitoringLib)
       endforeach()
endfunction()

SETUP_TESTS(
   test1
)

