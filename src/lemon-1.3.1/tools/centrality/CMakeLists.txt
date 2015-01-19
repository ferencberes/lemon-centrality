INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
)

LINK_DIRECTORIES(
  ${PROJECT_BINARY_DIR}/lemon
)

ADD_EXECUTABLE(centrality_test centrality_test.cc list_digraph_for_centrality.h centrality_utils.h)
TARGET_LINK_LIBRARIES(centrality_test lemon)

ADD_EXECUTABLE(centrality_acceptence_test centrality_acceptence_test.cc)
TARGET_LINK_LIBRARIES(centrality_acceptence_test lemon)

#INSTALL(
#  TARGETS lgf-gen dimacs-to-lgf dimacs-solver
#  RUNTIME DESTINATION bin
#  COMPONENT bin
#)

#IF(NOT WIN32)
#  INSTALL(
#    PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/lemon-0.x-to-1.x.sh
#    DESTINATION bin
#    COMPONENT bin
#  )
#ENDIF()
