/**
 * @file wposition1.h
 * Individual world location in geodetic earth coordinates (latitude, longitude, and altitude).
 */
#ifndef USML_TYPES_WPOSITION1_H
#define USML_TYPES_WPOSITION1_H

#include <usml/ublas/ublas.h>
#include <usml/types/wvector1.h>
#include <usml/types/wposition.h>

namespace usml {
namespace types {
/// @ingroup wposition
/// @{

/**
 * World location in geodetic earth coordinates (latitude, longitude,
 * and altitude). Each of the three coordinate parameters is a scalar.
 * This class is a convenience to save the developer from doing a lot of 
 * operations on 1x1 matrices.
 */
class wposition1: public wvector1
{

public:

    //*********************************
    // initialization

    /** 
     * Constructs an individual position.
     *
     * @param  lat          Initial latitude
     * @param  lng          Initial longitude
     * @param  alt          Initial altitude
     */
    wposition1(double lat = 0.0, double lng = 0.0, double alt = 0.0);

    /** 
     * Constructs a new position as a copy of an existing position.
     * Accepts either an actual wposition, or one of its superclasses.
     *
     * @param  other		wposition1 to be copied.
     */
    wposition1(const wvector1& other);

    /**
     * Copy one element from a matrix of world vectors.
     */
    wposition1(const wvector& other, unsigned row, unsigned col);

public:

    //******************************
    // Altitude property

    /** 
     * Retrieves the altitude above the mean sea level.
     * Acts as a convenient transformation of the "Rho" property.
     *
     * @return			Altitude in meters.
     */
    inline double altitude() const {
        return rho() - wposition::earth_radius;
    }

    /** 
     * Defines the altitude above the mean sea level.
     * Acts as a convenient transformation of the "Rho" property.
     *
     * @param  altitude	Altitude in meters.
     */
    inline void altitude(double altitude) {
        rho(altitude + wposition::earth_radius);
    }

    //******************************
    // Latitude property

    /** 
     * Retrieves the latitude component of geodetic earth coordinates. 
     * Acts as a convenient transformation of the "Theta" property. 
     * 
     * @return          Latitude component in degrees.
     */
    inline double latitude() const {
        return to_latitude(theta());
    }

    /** 
     * Defines the latitude component of geodetic earth coordinates.
     * Acts as a convenient transformation of the "Theta" property.
     *
     * @param  latitude	Latitude component in degrees.
     */
    inline void latitude(double latitude) {
        theta(to_colatitude(latitude));
    }

    //******************************
    // Longitude property

    /** 
     * Retrieves the longitude component of geodetic earth coordinates.
     * Acts as a convenient transformation of the "Theta" property.
     *
     * @return			Longitude component in degrees.
     */
    inline double longitude() const {
        return to_degrees(phi());
    }

    /** 
     * Defines the longitude component of geodetic earth coordinates.
     * Acts as a convenient transformation of the "theta" property.
     *
     * @param  longitude	Longitude component in degrees.
     */
    inline void longitude(double longitude) {
        phi(to_radians(longitude));
    }
};

/// @}
} // end of ocean namespace
} // end of usml namespace

#endif
