# Arduino-Waterlevel-Coffeemaker
System based on Arduino Nano to indicate low water level in coffeemaker with external perspex water tank.

Project on Hackaday: https://hackaday.io/project/171487-water-level-alarm-for-coffee-maker

Code for Arduino Nano is provided in this repository. Monitor resistance of photoresistor while powering laser LED to penetrate said photoresistor. At low water level, laser doesn't hit the sensor anymore, resistance goes up and Arduino makes alarm (light & sound) go off.