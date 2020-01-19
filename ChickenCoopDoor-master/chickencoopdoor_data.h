const int StepperPin1 = A2;
const int StepperPin2 = A4;
const int MotorControlPin1 = 6;
const int MotorControlPin2 = 8;

const int DaylightPin = A6; // defaults to INPUT mode

struct LightData  {
	int lightLevel;
	bool isConsistent;  // not used but could be useful in real-world scenario
};

// sensor provides good light/dark outputs, use midpoint to detect state
const int LightMidpoint = 50;
