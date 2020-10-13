#ifndef msr_airlib_aircraftparams_hpp
#define msr_airlib_aircraftparams_hpp

#include "common/Common.hpp"

namespace msr
{
	namespace airlib
	{
		/* Implement single value linear aero derviatives, american coefficent is used, see https://aerocastle.files.wordpress.com/2012/04/flightdynamicsprinciples.pdf Cook Book
		   All values are defaulted to zero so if not called has *no effect*, for higher order terms in particular.
		   Derivatives are in the wind/stability axis so need to be converted to body and then earth/NED
		   SI units & radians throughout*/
		//TODO: Include cross terms eg CLr
		struct LinearAeroDerivatives
		{
			real_T zero_lift_coefficient = 0; // CL0, zero alpha lift coefficient
			real_T alpha_lift_coefficient = 0; // CLalpha, lift curve gradient
			real_T pitch_lift_coefficient = 0; // CLq, (due to alpha dot)
			real_T elev_lift_coefficient = 0; // CLelev, lift due to aileron deflection

			real_T zero_drag_coefficient = 0; // CD0, zero alpha drag coefficient
			real_T alpha_drag_coefficient = 0; // CDalpha, drag curve gradient
			real_T alpha_drag_coefficient_2 = 0; // CDalpha_squared, second order drag curve gradient
			real_T beta_drag_coefficient = 0; // CDbeta, beta drag curve gradient (assume beta0 is always zero)
			real_T beta_drag_coefficient_2 = 0; // CDbeta_squared, second order beta drag curve gradient
			real_T pitch_drag_coefficient = 0; // CDq, (due to alpha dot)
			real_T elev_drag_coefficient = 0; // CLelev, lift due to aileron deflection

			real_T zero_sideforce_coefficient = 0; // CY0, zero beta sideforce coefficient
			real_T beta_sideforce_coefficient = 0; // Cbeta, sideforce due to beta
			real_T rollrate_sideforce_coefficient = 0; // CYp, sideforce due to rollrate coefficient
			real_T yawrate_sideforce_coefficient = 0; // CYr, sideforce due to yawrate coefficient
			real_T sidevelocity_sideforce_coefficient = 0; // CYv, (beta dot?)
			real_T rudder_sideforce_coefficient = 0; //CYrudder, sideforce due to rudder deflection
			real_T aileron_sideforce_coefficient = 0; //CYaileron, sideforce due to aileron deflection

			real_T zero_roll_coefficient = 0; // Cl0, trim roll moment coefficient
			real_T beta_roll_coefficient = 0; // Clbeta, roll moment due to beta
			real_T rollrate_roll_coefficient = 0; // Clp, roll velocity roll moment coefficient
			real_T yawrate_roll_coefficient = 0; // Clr, yaw rate roll moment coefficient
			real_T aileron_roll_coefficient = 0; // roll due to aileron deflection
			real_T rudder_roll_coefficient = 0; // roll due to rudder deflection

			real_T zero_pitch_coefficient = 0; // CM0, zero alpha pitch coefficient
			real_T alpha_pitch_coefficient = 0; // CMalpha, pitch curve gradient
			real_T pitchrate_pitch_coefficient = 0; // CMq, pitching moment pitching velocity coefficient
			real_T elevator_pitch_coefficient = 0; // CMelev, Pitching moment generated by elevator

			real_T zero_yaw_coefficient = 0; // Cn0, zero yaw yawing moment
			real_T beta_yaw_coefficient = 0; // Cnbeta, yawing mom due to beta
			real_T rollrate_yaw_coefficient = 0; // Cnp, yawing mom roll rate coefficient
			real_T yawrate_yaw_coefficient = 0; // Cnr, yawing moment yaw rate coefficient
			real_T rudder_yaw_coefficient = 0; // yaw due to rudder deflection
			real_T aileron_yaw_coefficient = 0; // yaw due to aileron deflection
		};

		struct PropulsionDerivatives
		{
			real_T thrust_tla_coefficient = 0; // CTtla, thrust produced with tla deflection (original simplified definition)
			real_T propeller_area = 0; // Sprop, propellor area
			real_T propeller_thrust_coefficient = 0; // CTv, thrust produced by the propellor at a given velocity
			real_T k_motor_coefficient = 0; // k_motor, efficiency of the motor in terms of velocity change produced
			real_T propeller_torque_coefficient = 0; // K_omega, torque produced by propellor due to rate of rotation
			real_T motor_torque_coefficient = 0; // K_tp, torque produced due to thrust
			


		};

		struct Dimensions
		{
			real_T main_plane_area = 0; // S, area of main wing [m^2]
			real_T horizontal_tail_plane_area = 0; // S_hT, area of horizontal tailplane
			real_T vertical_tail_plane_area = 0; // S_vT, area of vertical tailplane
			real_T main_plane_span = 0; // b, wing span
			real_T main_plane_chord = 0;
		};

		// Aero angles
		struct AoA
		{
			real_T alpha;
			real_T psi; // aero roll?
			real_T beta;
			Vector3r aero_axis;
		};

		// Aero Forces and Moments
		struct AeroFM
		{
			real_T lift;
			real_T drag;
			real_T thrust;
			real_T weight;
			real_T side_force;
			real_T pitch_mom;
			real_T roll_mom;
			real_T yaw_mom;
		};
	}
}
#endif
