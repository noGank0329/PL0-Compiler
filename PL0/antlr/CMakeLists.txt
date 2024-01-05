
file(GLOB libantlrcpp_SRC
        "${PROJECT_SOURCE_DIR}/antlr/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/antlr/src/atn/*.cpp"
        "${PROJECT_SOURCE_DIR}/antlr/src/dfa/*.cpp"
        "${PROJECT_SOURCE_DIR}/antlr/src/misc/*.cpp"
        "${PROJECT_SOURCE_DIR}/antlr/src/support/*.cpp"
        "${PROJECT_SOURCE_DIR}/antlr/src/tree/*.cpp"
        "${PROJECT_SOURCE_DIR}/antlr/src/tree/pattern/*.cpp"
        "${PROJECT_SOURCE_DIR}/antlr/src/tree/xpath/*.cpp"
)

target_sources(${PROJECT_NAME} PRIVATE ${libantlrcpp_SRC})

