#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <conio.h>

#include <stdlib.h>
#include <gclib.h>
#include <gclibo.h>
#include <gclib_errors.h>
#include <gclib_record.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Galil.h"

using namespace System;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Threading::Tasks;

GCon g = 0; // Var used to refer to a unique connection


int main()
{
	
	char buf[1024]; //traffic buffer
	char Command[128] = "";

	GOpen("192.168.0.120 -d", &g);

	sprintf_s(Command, "AO0,0;");

	GCommand(g, Command, buf, sizeof(buf), 0);

	if (g)
		GClose(g); // Don't forget to close!

	Console::WriteLine("Terminating!");
	Console::ReadKey();



	/*EmbeddedFunctions* Funcs;
	Galil MyGalil(Funcs, "192.168.0.120 -d");*/
	
	return G_NO_ERROR;

	
}

//-----------------------------

//Galil::Galil() {
//
//}
//Galil::Galil(EmbeddedFunctions* Funcs, GCStringIn address) {
//
//}
//
// 
//void Galil::DigitalOutput(uint16_t value) {
//
//}
//void Galil::DigitalByteOutput(bool bank, uint8_t value) {	
//																// Write to one byte, either high or low byte, as specified by user in 'bank'
//}																	// 0 = low, 1 = high
//void Galil::DigitalBitOutput(bool val, uint8_t bit) {			// Write single bit to digital outputs. 'bit' specifies which bit
//
//}
//// DIGITAL INPUTS
//uint16_t Galil::DigitalInput() {						// Return the 16 bits of input data
//
//													// Query the digital inputs of the GALIL, See Galil command library @IN
//}
//uint8_t Galil::DigitalByteInput(bool bank) {			// Read either high or low byte, as specified by user in 'bank'
//
//}													// 0 = low, 1 = high
//bool Galil::DigitalBitInput(uint8_t bit)				// Read single bit from current digital inputs. Above functions
//{													// may use this function
//
//}
//bool Galil::CheckSuccessfulWrite()						// Check the string response from the Galil to check that the last 
//{													// command executed correctly. 1 = succesful. NOT AUTOMARKED
//
//}
//// ANALOG FUNCITONS
//float Galil::AnalogInput(uint8_t channel) {						// Read Analog channel and return voltage		
//
//}
//void Galil::AnalogOutput(uint8_t channel, double voltage){		// Write to any channel of the Galil, send voltages as
//														// 2 decimal place in the command string
//}
//void Galil::AnalogInputRange(uint8_t channel, uint8_t range) {	// Configure the range of the input channel with
//														// the desired range code
//}
//
//// ENCODER / CONTROL FUNCTIONS
//void Galil::WriteEncoder() {
//}								// Manually Set the encoder value to zero
//int Galil::ReadEncoder() {
//	// Read from Encoder
//}
//void Galil::setSetPoint(int s) {							// Set the desired setpoint for control loops, counts or counts/sec
//
//}
//void Galil::setKp(double gain) {							// Set the proportional gain of the controller used in controlLoop
//
//}
//void Galil::setKi(double gain) {							// Set the integral gain of the controller used in controlLoop()
//
//}
//void Galil::setKd(double gain) {							// Set the derivative gain of the controller used in controlLoop()
//
//}
//void Galil::PositionControl(bool debug, int Motorchannel) {	// Run the control loop. ReadEncoder() is the input to the loop. The motor is the output.
//													// The loop will run using the PID values specified in the data of this object, and has an 
//													// automatic timeout of 10s. You do not need to implement this function, it is defined in
//													// GalilControl.lib
//}
//void SpeedControl(bool debug, int Motorchannel) {
//
//
//}
