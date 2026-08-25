include(FetchContent)
FetchContent_Declare(
    cli11_proj
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.7.2
    SYSTEM
)

FetchContent_MakeAvailable(cli11_proj)

add_executable(emdl1_sandbox emdl1_sandbox.cpp ../emdL1.cpp)
target_link_libraries(emdl1_sandbox PRIVATE CLI11::CLI11)
