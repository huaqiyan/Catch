/*
 *  Created by Phil on 29/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch.hpp"

inline bool itDoesThis(){ return true; }
inline bool itDoesThat(){ return true; }

SCENARIO( "Do that thing with the thing", "[Tags]" ) {
    GIVEN( "This stuff exists" ) {
        // make stuff exist
        WHEN( "I do this" ) {
            // do this
            THEN( "it should do this")
            {
                REQUIRE( itDoesThis() );
                AND_THEN( "do that")
                    REQUIRE( itDoesThat() );
            }
        }
    }
}

SCENARIO( "Vector resizing affects size and capacity", "[vector][bdd][size][capacity]" ) {
    GIVEN( "an empty vector" ) {
        std::vector<int> v;
        REQUIRE( v.size() == 0 );
        
        WHEN( "it is made larger" ) {
            v.resize( 10 );
            THEN( "the size and capacity go up" ) {
                REQUIRE( v.size() == 10 );
                REQUIRE( v.capacity() >= 10 );
                
                AND_WHEN( "it is made smaller again" ) {
                    v.resize( 5 );
                    THEN( "the size goes down but the capacity stays the same" ) {
                        REQUIRE( v.size() == 5 );
                        REQUIRE( v.capacity() >= 10 );
                    }
                }
            }
        }
        
        WHEN( "we reserve more space" ) {
            v.reserve( 10 );
            THEN( "The capacity is increased but the size remains the same" ) {
                REQUIRE( v.capacity() >= 10 );
                REQUIRE( v.size() == 0 );
            }
        }
    }
}

SCENARIO(   "This is a really long scenario name to see how the list command deals with wrapping",
            "[very long tags][lots][long][tags][verbose]"
            "[one very long tag name that should cause line wrapping writing out using the list command]"
            "[anotherReallyLongTagNameButThisOneHasNoObviousWrapPointsSoShouldSplitWithinAWordUsingADashCharacter]" ) {
}
