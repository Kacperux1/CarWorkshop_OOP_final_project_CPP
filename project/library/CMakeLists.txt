cmake_minimum_required(VERSION 3.4)
project(Library)

# podkatalog z biblioteką cereal
add_subdirectory(cereal)

#  pliki źródłowe dla projektu Library
set(SOURCE_FILES
        include/typedefs.h
        src/model/Client.cpp
        include/model/Client.h
        src/model/Car.cpp
        include/model/Car.h
        src/model/RepairOrder.cpp
        include/model/RepairOrder.h
        src/model/RepairType.cpp
        include/model/RepairType.h
        src/model/GeneralInspection.cpp
        include/model/GeneralInspection.h
        src/model/GearboxRepair.cpp
        include/model/GearboxRepair.h
        src/model/LPGInstallation.cpp
        include/model/LPGInstallation.h
        src/model/EngineChange.cpp
        include/model/EngineChange.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/repositories/RepairOrderRepository.cpp
        include/repositories/RepairOrderRepository.h
        src/repositories/CarRepository.cpp
        include/repositories/CarRepository.h
        src/managers/ClientManager.cpp
        include/managers/ClientManager.h
        src/managers/CarManager.cpp
        include/managers/CarManager.h
        src/managers/RepairOrderManager.cpp
        include/managers/RepairOrderManager.h
)

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES}
       )

# Dołącz katalogi z plikami nagłówkowymi
include_directories(cereal/include)


target_link_libraries(Library cereal)

# Opcje kompilacji dla targetu Library
target_compile_options(Library
        PUBLIC -std=c++11)

# Plik konfiguracyjny dla cereal
configure_file("./cereal/Config.cmake.in" @ONLY)


target_include_directories(Library PUBLIC include)


enable_testing()


find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)


include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

# Pliki źródłowe dla testów
set(SOURCE_TEST_FILES
        test/master.cpp
        src/model/Client.cpp
        include/model/Client.h
        src/model/Car.cpp
        include/model/Car.h
        src/model/RepairOrder.cpp
        include/model/RepairOrder.h
        src/model/RepairType.cpp
        include/model/RepairType.h
        src/model/GeneralInspection.cpp
        include/model/GeneralInspection.h
        src/model/GearboxRepair.cpp
        include/model/GearboxRepair.h
        src/model/LPGInstallation.cpp
        include/model/LPGInstallation.h
        src/model/EngineChange.cpp
        include/model/EngineChange.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/repositories/RepairOrderRepository.cpp
        include/repositories/RepairOrderRepository.h
        src/repositories/CarRepository.cpp
        include/repositories/CarRepository.h
        src/managers/ClientManager.cpp
        include/managers/ClientManager.h
        src/managers/CarManager.cpp
        include/managers/CarManager.h
        src/managers/RepairOrderManager.cpp
        include/managers/RepairOrderManager.h
        test/ClientTest.cpp
        test/CarTest.cpp
        test/RepairOrderTest.cpp
        test/EngineChangeTest.cpp
        test/GearboxRepairTest.cpp
        test/GeneralInspectionTest.cpp
        test/LPGInstallationTest.cpp
        test/CarRepositoryTest.cpp
        test/ClientRepositoryTest.cpp
        test/RepairOrderRepositoryTest.cpp
        test/CarManagerTest.cpp
        test/ClientManagerTest.cpp
        test/RepairOrderManagerTest.cpp
)


add_executable (LibraryTester ${SOURCE_TEST_FILES}
        test/CarRepositoryTest.cpp
        test/ClientRepositoryTest.cpp
        test/RepairOrderRepositoryTest.cpp
        test/CarManagerTest.cpp
        test/ClientManagerTest.cpp
        test/RepairOrderManagerTest.cpp
)


target_link_libraries (LibraryTester
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)


add_test(LibraryTest LibraryTester
        --report_level=detailed
        --log_level=all
        --color_output=yes)


add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
