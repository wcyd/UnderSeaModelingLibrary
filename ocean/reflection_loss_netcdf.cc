/** 
 * @file reflect_loss_netcdf.cc
 * Models plane wave reflection from a bottom province profile.
 */
#include <usml/ocean/reflect_loss_netcdf.h>

using namespace usml::ocean ;

/**
 * Opens the netcdf file, [filename], and grabs the following data:
 *
 *	@dim num_types	   : the number of bottom provinces
 *	@var lat	   : latitude in degrees
 *	@var lon	   : longitude in degrees
 *	@var type	   : predetermined bottom province number
 *	@var speed_ratio   : specific speed ratio for [type]
 *	@var density_ratio : specific density ratio for [type]
 *	@var atten	   : attenuation value for [type]
 *	@var shear_speed   : specific shear speed for [type]
 *	@var shear_atten   : specific speed atten for [type]
 *
 */

	NcFile file( filename );
	NcDim *_n = file.get_dim("num_types");
	NcVar *_lat = file.get_var("lat");
	NcVar *_lon = file.get_var("lon");
	NcVar *bot_num = file.get_var("type");
	NcVar *bot_speed = file.get_var("speed_ratio");
	NcVar *bot_density = file.get_var("density_ratio");
	NcVar *bot_atten = file.get_var("atten");
	NcVar *bot_shear_speed = file.get_var("shear_speed");
	NcVar *bot_shear_atten = file.get_var("shear_atten");

/***************************************************************
	double bot_prov_dataIn[sizeof(_lat)][sizeof(_lon)];

	data_grid<double,2> bottom_prov_grid;
	bottom_prov_grid->get(bot_prov_dataIn[0][0],)
***************************************************************/

private:

	reflection_loss_rayleigh rayleigh[_n];

for(int i=0; i<_n; i++) {
	rayleigh[i] =  reflect_loss_rayleigh( 
	        double bot_density[i], double bot_speed[i], double bot_atten[i],
	        double bot_shear_speed[i], double bot_shear_atten[i] ) ;
}

	// build the data grid with the axis of lat and lon and the innerds as the prov #s

	// reflection_loss( const wposition1& location, const seq_vector& frequencies, double angle, blah......)
	// find the prov # for above location from data grid
	// rayleigh[above prov #].reflection_loss(all that jazz);
