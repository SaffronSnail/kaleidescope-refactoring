get-token.o: get-token.cpp get-token.hpp token.hpp
	clang++ -c ${CXXFLAGS} get-token.cpp

