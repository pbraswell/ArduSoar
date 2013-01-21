 /// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: t -*-

/*
 *  ArduSoar support functions
 *
 *  Peter Braswell 
 * 
 *  This firmware is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 */
 
 // Keep track of the previous flight mode so we can transition back
 // When we come out of thermal mode.
 static FlightMode previous_control_mode;
 
 // Check to see if see if we should be thermalling
 static FlightMode thermal(FlightMode current_control_mode) {\

   FlightMode calculated_control_mode = current_control_mode;
   
   if( g.soar_active == 1 ) {
     
     if (read_climb_rate() > g.thermal_vspeed ) {
       previous_control_mode = current_control_mode;
       calculated_control_mode =  CIRCLE;
     }
   }
   
   return calculated_control_mode;
   
 }
 
 // Check to see if we've topped out of a thermal and 
 // Should transition to cruise (or rather the previous control mode).
 static FlightMode cruise(FlightMode current_control_mode) {
   
   FlightMode calculated_control_mode = current_control_mode;
 
   if ( g.soar_active == 1 ) {
     
     if (read_climb_rate() < 0 ) {
       calculated_control_mode =  previous_control_mode;
     }
   }
   
   return calculated_control_mode;
 }
