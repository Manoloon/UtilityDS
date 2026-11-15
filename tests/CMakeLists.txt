include(FetchContent)
FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.7.0
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(unity)
add_executable(test_dynamicArray test_dynamicArray.c)
target_link_libraries(test_dynamicArray PRIVATE UtilityDS unity)

add_test(NAME DynamicArrayTests COMMAND UtilityDS)