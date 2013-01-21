This is a fork of ArduPlane that supports thermal soaring.

WARNINGS:
=========
This is a highly experimental version of ArduPlane based one ArduPlan v2.68. 
This version of ArduPlane as of now (January 21, 2013) has only been simulator tested
in X-Plane.  I'll update this document as more testing (eventually live) is complete

Description
-----------
I have modified it to have a basic "soaring" or thermal mode.  This is primarily intended 
for sailplane pilots who want an autonomous soaring. As of this initial Alpha release, the 
software has only been tested in X-Plane v10.  The results are promising.  I've been able
to fly a several 30KM tasks with an electric sailplane model in varying soaring conditions
ranging from strong thermals extending to 10,000 feet to a relatively modest day where
thermals are sparse and top out at only 3000 feet.  More testing however needs to be done.

I envision this software used in two modes, at least as I'm conceptualizing it at this point.
One mode is soaring assist whereby a fly-by-wire mode (FBW-A in this case) is modified with
a thermal hunting mode based on rate-of-climb.  When the ROC exceeds a variable parameter, 
the aircraft goes into CIRCLE mode.  This is simplistic.  It can probably be enhanced, but
it seems to work surprisingly well.

The other mode is full autonomous soaring from way point to way point.  In this mode, I've
modified the AUTO mode to contain the same thermal hunting algorithm explained above.  In this 
mode, a flight is planned and uploaded via the APM flight planner and the flight is autonomously
flown from way point to way point.  

More information here: [ArduPlane / DIYDrones website](http://www.diydrones.com)
Specifically take a look at the ArduPlane manual.

I've modified two internal flight modes for to enable soaring:

*FLY By Wire 'A'*
I've modified this mode to incorporate a thermal hunting mode based on rate of climb.  

*Auto*
Similarly, I've added the same thermal hunting algorithm allowing the plane to fly 
a planned mission, stopping along the way to circle if ArduPilot senses a rate of climb
above the specified value.

Setup and Configuration
------------------------
I've included only the source code in this repository.  You'll have to be familiar with Arduino programming and
the Arduino environment to compile and upload the code.  Good documentation can again be found on the [DIYDrones.com website](http://www.diydrones.com).

To compile for simulation verses real hardware, see APM_Config.h.  There you will find the appropriate #define to turn on / off the 
hardware in loop (HIL) simulation.  

Once the software is compiled and uploaded, connect via the mission planner.  You'll notice two new parameters 
on the advanced parameters page:

*SOAR_ACTIVE (0=Soaring disabled and 1=Soaring enabled)*
*THERMAL_VSPEED (thermal speed in m/s that triggers thermal mode)*

"SOAR_ACTIVE" is pretty straight forward.  "THERMAL_VSPEED" takes a little tuning and is driven by the thermal strength.  If you set this value too
low, you'll find yourself constantly circling.  Set it too low and you'll not stop enough to thermal.  You can set the thermal
activity in X-Plane by setting it in the "Environment->Weather" menu setting.  For initial experimentation, try the following:

*In APM Mission Planner:*
SOAR_ACTIVE 1 (soaring mode enabled)
THERMAL_VSPEED (between 2-3 m/s)
Don't forget to write parameters to the AP

*In X-Plane*
Environment=>Weather=>Thermal tops = 3500'
Environment=>Weather=>Thermal coverage = 10%
Environment=>Weather=>Thermal strength = 350' fpm

This should allow you to fly a 30KM or so triangle.  I haven't played with downloading real weather or seeing how different winds affect 
the simulation

To Do's
-------
* Develop a damper for thermal enter and thermal exit
* Integrate a thermal band, e.g. if you're higher than X feet, don't stop to thermal.
* Intelligent inter-thermal speeds based on lift and / or aircraft polar
* Smarter thermal centering
* 






