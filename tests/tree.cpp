#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating tree")
{
	tree_t tree;
	REQUIRE( tree.root() == nullptr );
}
