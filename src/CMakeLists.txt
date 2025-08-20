add_executable(CHIPPIE
  main.cpp
)

# Yep, that's it!
target_link_libraries(CHIPPIE
  PUBLIC
    ImGui-SFML::ImGui-SFML
)

include(Install.cmake)