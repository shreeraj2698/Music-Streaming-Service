if(EXISTS "/Users/shree/Downloads/Music-Streaming-Service/src/libs/metadata/test/test-metadata[1]_tests.cmake")
  include("/Users/shree/Downloads/Music-Streaming-Service/src/libs/metadata/test/test-metadata[1]_tests.cmake")
else()
  add_test(test-metadata_NOT_BUILT test-metadata_NOT_BUILT)
endif()
