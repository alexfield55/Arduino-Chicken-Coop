For now, this readme is simply NOTES. Maybe later it will turn into a good description of the project and its specification/design.

Chicken Coop Door Project
	Requirements
		Closes door at sundown
		Opens door at sunrise
		Does not close if there are any obstructions (what kind of sensor?)
	Aspirations
		Store temperature data inside chicken coop with respect to time?

Project Dependencies
	Software
		perhaps https://github.com/PaulStoffregen/Time
	Hardware
		Arduino Nano chip with ATMega328P microcontroller, https://store.arduino.cc/usa/arduino-nano
		DC 12V 320rpm Encode Gear Reducer Motor Electric Gear Box Motor, https://www.banggood.com/DC-12V-320rpm-Encode-Gear-Reducer-Motor-Electric-Gear-Box-Motor-p-1068577.html
		KOOKYE photosensitive light sensor module (no. 12?) -- not very much documentation
		Geekcreit L298N Dual H Bridge Stepper Motor Driver Board For Arduino, https://www.banggood.com/Wholesale-Dual-H-Bridge-DC-Stepper-Motor-Drive-Controller-Board-Module-Arduino-L298N-p-42826.html?cur_warehouse=USA
		
Power
	Motor - rated at 12V (DC), optimal operating current = 0.6A, max current = 1.2A, min current = 0.15 (at no load)
	Arduiono Nano chip - operates at 5V and consumes 19mA of current, may provide 7V-12V as input, can output 40mA as DC output per pin
	
Pins
	4 pins for the motor (2 for encoder, 2 for control)
	2 for the stepper
	
Wiring
	
	VCC means positive input voltage (pin)

	Photo resistor
		D0 (yellow) -> A6 on arduino
		GND (red) -> (black) GND on arduino
		VCC (black) -> (red) A7 on arduino
	
	Motor
		M1 (red) -> OUT2 on stepper
		GND (black) -> GND on stepper
		C1 (yellow) -> D8 on arduino
		C2 (green) -> D6 on arduino
		VCC (blue) -> 12V input pin on stepper
		M2 (white) -> OUT1 on stepper
		
	Power adapter
		
		1 pin to 12V input on stepper and 1 pin to GND on stepper
		
	Stepper (2 left that have not already been mentioned)
	
		IN1 -> A4 on arduino
		IN2 -> A2 on arduino