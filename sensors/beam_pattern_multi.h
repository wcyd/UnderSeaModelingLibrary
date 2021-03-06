/**
 * @file beam_pattern_multi.h
 * Beam pattern that is a combination of other beam patterns.
 */
#pragma once

#include <usml/sensors/beam_pattern_model.h>
#include <list>

namespace usml {
namespace sensors {

/// @ingroup beams
/// @{

/**
 * Models a multi-pattern beam. This class is for instances
 * where the user requires that a beam pattern be modeled as
 * the combination of two or more beams, to produce the physical
 * representation of the beam.
 */
class USML_DECLSPEC beam_pattern_multi
   : public beam_pattern_model
{

public:

    /**
     * Constructor
     * Takes a list of beam patterns and stores them locally to be used
     * when requesting a beam level.
     * @param beam_list list of pointers to beam_pattern_model's. This class 
     *                  takes ownership of the beam_pattern_model pointers,
     *                  and deletes them on destruction.
     */
    beam_pattern_multi( std::list<beam_pattern_model*> beam_list ) ;

    /**
     * Destructor
     */
    virtual ~beam_pattern_multi() ;

    /**
     * Computes the response level in a specific DE/AZ pair and
     * beam steering angle. The return, level, is passed
     * back in linear units.
     *
     * @param de            Depression/Elevation angle (rad)
     * @param az            Azimuthal angle (rad)
     * @param orient        Orientation of the array
     * @param frequencies   List of frequencies to compute beam level for
     * @param level         Beam level for each frequency (squared linear units)
     */
    virtual void beam_level( double de, double az,
                             orientation& orient,
                             const vector<double>& frequencies,
                             vector<double>* level) ;

    /**
     * Computes the directivity index for a list of frequencies
     *
     * @param frequencies   frequencies to determine DI at
     * @param level         gain for the provided frequencies
     */
    virtual void directivity_index( const vector<double>& frequencies,
                                    vector<double>* level ) ;

private:

    /**
     * List of beam patterns associated with this multi-pattern
     */
    std::list<beam_pattern_model*>  _beam_list ;

};

/// @}
}   // end of namespace sensors
}   // end of namespace usml
