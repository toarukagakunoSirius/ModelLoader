

#include <iostream>
#include "catch.hpp"
#include "Model.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
	SECTION( "Testing loaded data" ) { 
	string FileName = "Model.mod";
		Model M = Model();
		M.LoadModel(FileName);
		REQUIRE( M.NumberVertices() == 301 );
		
	}
	
}

