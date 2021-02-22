//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

// Write your code here

class GPS{
double latitude;
double longitude;
Compass latitudeirection;
Compass longitudedirecton;
public:
  GPS(double lat, Compass comp, double longt, Compass longdirt){
    latitude = lat;
    longitude = longt;
    if (lat > 90 || lat < 0){
      latitude = 0;
      latitudeirection = Compass::N;
    
    }
    if (longt > 180 || longt < 0){
      longitude = 0;
      longitudedirecton = Compass::W;
    }
     if (comp == Compass::W || comp == Compass::E){
      latitudeirection = Compass::N;
    }
    if (longdirt == Compass::N || longdirt == Compass::S){
      longitudedirecton = Compass::W;
    }
  }
  GPS(double lat, double longt){
    latitude = lat;
    longitude = longt;
    latitudeirection = Compass::N;
    longitudedirecton = Compass::W;
    if (lat > 90 || lat < 0){
      latitude = 0;
      latitudeirection = Compass::N;
    }
    if (longt > 180 || longt < 0){
      longitude = 0;
      longitudedirecton = Compass::W;
    }
    latitudeirection = Compass::N;
    longitudedirecton = Compass::W;
  }
  GPS(){
    latitude = 0;
    longitude = 0;
    latitudeirection = Compass::N;
    longitudedirecton = Compass::W;
  }
double getLatitude() {
return latitude;
}
double getLongitude() {
return longitude;
}
Compass getLongitudeDirection() {
return longitudedirecton;
}
Compass getLatitudeDiection() {
return latitudeirection;
}
};
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
